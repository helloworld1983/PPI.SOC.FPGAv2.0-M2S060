----------------------------------------------------------------------------------
-- Company:         Prototype Performance Incorporated
-- Engineer:        Scott Walker
-- 
-- Create Date:     17 August 2014 
-- Design Name:     Powered Rail Performance Tester 
-- Module Name:     FIFOs.vhd - Behavioral 
-- Project Name:    Powered Rail Performance Tester
-- Target Devices:  TBD
-- Description:     
--     The FIFOs consist of both a Transmit FIFO and Receive FIFO.  The Transmit 
--     FIFO provides an 8-bit interface to the AMBA write data interface and an 
--     8-bit interface to the Transmit Packet Processor.  The Receive FIFO provides 
--     an 8-bit interface to the AMBA read data interface and an 8-bit interface 
--     to the Receive Packet Processor.  Both the Transmit FIFO and Receive FIFO 
--     are 2048 bytes in depth. 
-- Structure:
--    CommsFPGA_top.vhd
--      -- uP_if.vhd
--           -- Interrupts.vhd
--      -- ManchesterEncoder.vhd
--           -- TX_SM.vhd
--                -- IdleLineDetector.vhd
--           -- CRC16_Generator.vhd
--      -- FIFOs.vhd                          <=
--           -- FIFO_1Kx8.vhd
--      -- ManchesDecoder.vhd 
--           -- AFE_RX_SM.vhd
--           -- ReadFIFO_Write_SM.vhd
--                -- CRC16_Generator.vhd
--           -- ManchesDecoder_Adapter.vhd
--                -- IdleLineDetector.vhd
--     
-- Revision:  0.1
--         
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_MISC.ALL;

library smartfusion2;
use smartfusion2.all;
library COREFIFO_LIB;
use COREFIFO_LIB.all;

entity FIFOs is
  Port (
    reset             : in  std_logic;
    DATA              : in  std_logic_vector(7 downto 0);
    TX_FIFO_wr_clk    : in  std_logic;
    TX_FIFO_rd_clk    : in  std_logic;
    TX_FIFO_wr_en     : in  std_logic;
    TX_FIFO_rd_en     : in  std_logic;
    TX_FIFO_DOUT      : out std_logic_vector(7 downto 0);
    TX_FIFO_AE        : out std_logic;
    TX_FIFO_Empty     : out std_logic;
    TX_FIFO_Full      : out std_logic;
    TX_FIFO_AF        : out std_logic;
    TX_FIFO_OVERFLOW  : out std_logic;
    TX_FIFO_UNDERRUN  : out std_logic;
    TX_FIFO_RST       : in  std_logic;
    RX_FIFO_wr_clk    : in  std_logic;
    RX_FIFO_rd_clk    : in  std_logic;
    RX_FIFO_wr_en     : in  std_logic;
    RX_FIFO_rd_en     : in  std_logic;
    RX_FIFO_DIN       : in  std_logic_vector(8 downto 0);
    RX_FIFO_DOUT      : out std_logic_vector(8 downto 0);
    RX_FIFO_Empty     : out std_logic;
    RX_FIFO_Full      : out std_logic;
    RX_FIFO_OVERFLOW  : out std_logic;
    RX_FIFO_UNDERRUN  : out std_logic;
    RX_FIFO_RST       : in  std_logic;
	rx_packet_complt  : in  std_logic;
	clk16x            : in std_logic;
	rx_packet_avail_int : in std_logic;
	up_EOP            : in std_logic;  		-- gwc 080217 increment FIFO read pointer
	FIFO_Ptr_Err	  : out std_logic;
	RX_FIFO_Empty_v   : out std_logic_vector(3 downto 0);  --091917
	done_w_active_rx_FIFO_en: in std_logic	-- 100517
  );
end FIFOs;

architecture Behavioral of FIFOs is

-- constants
  
-- signals
--  signal iTX_FIFO_DOUT          : std_logic_vector(7 downto 0);
  signal iTX_FIFO_Empty         : std_logic;
  signal itx_fifo_rst           : std_logic;
  signal irx_fifo_rst           : std_logic;
  signal RX_FIFO_AF             : std_logic_vector(3 downto 0);
  signal RX_FIFO_AE             : std_logic_vector(3 downto 0);
-- gwc	
  signal ReadFIFO_Write_Ptr	  : std_logic_vector(1 downto 0);
  signal ReadFIFO_Read_Ptr	  : std_logic_vector(1 downto 0);	
  signal iRX_FIFO_wr_en  	  : std_logic_vector(3 downto 0);	
  signal iRX_FIFO_rd_en  	  : std_logic_vector(3 downto 0);	
  signal iRX_FIFO_AE  	      : std_logic_vector(3 downto 0);	
  signal iRX_FIFO_AF  	      : std_logic_vector(3 downto 0);	
  signal iRX_FIFO_Empty  	  : std_logic_vector(3 downto 0);	
  signal iRX_FIFO_Full   	  : std_logic_vector(3 downto 0);	
  signal iRX_FIFO_OVERFLOW    : std_logic_vector(3 downto 0);	
  signal iRX_FIFO_UNDERRUN    : std_logic_vector(3 downto 0);	
  signal RX_FIFO_DOUT_0		  : std_logic_vector(8 downto 0);	
  signal RX_FIFO_DOUT_1		  : std_logic_vector(8 downto 0);	
  signal RX_FIFO_DOUT_2		  : std_logic_vector(8 downto 0);	
  signal RX_FIFO_DOUT_3		  : std_logic_vector(8 downto 0);	
  signal packet_available_clear_reg : std_logic_vector(2 downto 0); 
  signal iFIFO_Ptr_Err	 	  : std_logic  ;
  signal done_w_active_rx_FIFO_en_d: std_logic_vector(2 downto 0); 		-- 100517
  signal RX_FIFO_Reset_v	  : std_logic_vector(3 downto 0);
  signal Active_FIFO_rst	  : std_logic;
 
begin

  TX_FIFO_Empty <= iTX_FIFO_Empty;
  itx_fifo_rst  <= reset or TX_FIFO_RST;
  irx_fifo_rst  <= reset or RX_FIFO_RST;  -- 100217 enable Resets again on FIFOs
  FIFO_Ptr_Err <= iFIFO_Ptr_Err;
  RX_FIFO_Empty_v <= iRX_FIFO_Empty;  --091917
  
   
--------------------------------------------------------------------------------
-- Transmit FIFO
---------1---------2---------3---------4---------5---------6---------7---------8    
-- The Transmit FIFO provides an 2048 byte, 8-bit interface to the AMBA write 
-- data interface and an 8-bit interface to the Transmit Packet Processor. 
---------1---------2---------3---------4---------5---------6---------7---------8 

  TRANSMIT_FIFO : entity work.FIFO_2Kx8
    port map (
      DATA              => DATA, 
      RCLOCK            => TX_FIFO_rd_clk, 
      RE                => TX_FIFO_rd_en,  
      RESET             => itx_fifo_rst, 
      WCLOCK            => TX_FIFO_wr_clk, 
      WE                => TX_FIFO_wr_en, 
      AEMPTY            => TX_FIFO_AE, 
      AFULL             => TX_FIFO_AF,
      EMPTY             => iTX_FIFO_Empty, 
      FULL              => TX_FIFO_Full, 
      Q                 => TX_FIFO_DOUT,
      OVERFLOW          => TX_FIFO_OVERFLOW,
      UNDERFLOW         => TX_FIFO_UNDERRUN
    );

--------------------------------------------------------------------------------
-- Receive FIFO
---------1---------2---------3---------4---------5---------6---------7---------8    
-- The Receive FIFO provides an 2048 byte, 8-bit interface to the AMBA write 
-- data interface and an 8-bit interface to the Receive Packet Processor. 
---------1---------2---------3---------4---------5---------6---------7---------8 

  RECEIVE_FIFO_0 : entity work.FIFO_8Kx9
    port map (
      DATA              => RX_FIFO_DIN, 
      RCLOCK            => RX_FIFO_rd_clk, 
      RE                => iRX_FIFO_rd_en(0),
      RESET             => RX_FIFO_Reset_v(0), 
      WCLOCK            => RX_FIFO_wr_clk, 
      WE                => iRX_FIFO_wr_en(0),
      AEMPTY            => iRX_FIFO_AE(0), 
      AFULL             => iRX_FIFO_AF(0),
      EMPTY             => iRX_FIFO_Empty(0), 
      FULL              => iRX_FIFO_Full(0), 
      Q                 => RX_FIFO_DOUT_0,
      OVERFLOW          => iRX_FIFO_OVERFLOW(0),
      UNDERFLOW         => iRX_FIFO_UNDERRUN(0)     
    );

  RECEIVE_FIFO_1 : entity work.FIFO_8Kx9
    port map (
      DATA              => RX_FIFO_DIN, 
      RCLOCK            => RX_FIFO_rd_clk, 
      RE                => iRX_FIFO_rd_en(1),
      RESET             => RX_FIFO_Reset_v(1), 
      WCLOCK            => RX_FIFO_wr_clk, 
      WE                => iRX_FIFO_wr_en(1),
      AEMPTY            => iRX_FIFO_AE(1), 
      AFULL             => iRX_FIFO_AF(1),
      EMPTY             => iRX_FIFO_Empty(1), 
      FULL              => iRX_FIFO_Full(1), 
      Q                 => RX_FIFO_DOUT_1,
      OVERFLOW          => iRX_FIFO_OVERFLOW(1),
      UNDERFLOW         => iRX_FIFO_UNDERRUN(1)     
    );	

  RECEIVE_FIFO_2 : entity work.FIFO_8Kx9
    port map (
      DATA              => RX_FIFO_DIN, 
      RCLOCK            => RX_FIFO_rd_clk, 
      RE                => iRX_FIFO_rd_en(2),
      RESET             => RX_FIFO_Reset_v(2), 
      WCLOCK            => RX_FIFO_wr_clk, 
      WE                => iRX_FIFO_wr_en(2),
      AEMPTY            => iRX_FIFO_AE(2), 
      AFULL             => iRX_FIFO_AF(2),
      EMPTY             => iRX_FIFO_Empty(2), 
      FULL              => iRX_FIFO_Full(2), 
      Q                 => RX_FIFO_DOUT_2,
      OVERFLOW          => iRX_FIFO_OVERFLOW(2),
      UNDERFLOW         => iRX_FIFO_UNDERRUN(2)     
    );

  RECEIVE_FIFO_3 : entity work.FIFO_8Kx9
    port map (
      DATA              => RX_FIFO_DIN, 
      RCLOCK            => RX_FIFO_rd_clk, 
      RE                => iRX_FIFO_rd_en(3),
      RESET             => RX_FIFO_Reset_v(3), 
      WCLOCK            => RX_FIFO_wr_clk, 
      WE                => iRX_FIFO_wr_en(3),
      AEMPTY            => iRX_FIFO_AE(3), 
      AFULL             => iRX_FIFO_AF(3),
      EMPTY             => iRX_FIFO_Empty(3), 
      FULL              => iRX_FIFO_Full(3), 
      Q                 => RX_FIFO_DOUT_3,
      OVERFLOW          => iRX_FIFO_OVERFLOW(3),
      UNDERFLOW         => iRX_FIFO_UNDERRUN(3)     
    );	
  
  
--------------------------------------------------------------------------------
-- Read FIFO State Machine
---------1---------2---------3---------4---------5---------6---------7---------8 
  
  ReadFIFO_SM : process (irx_fifo_rst, clk16x)
  begin
    if (irx_fifo_rst = '1') then
      ReadFIFO_Write_Ptr  <= (others => '0');
	elsif (rising_edge(clk16x)) then 
	  if (rx_packet_complt = '1') then  -- good packet received
	    ReadFIFO_Write_Ptr <= ReadFIFO_Write_Ptr + '1';
	  else
	    ReadFIFO_Write_Ptr <= ReadFIFO_Write_Ptr;
	  end if ;		-- detect falling edge on packet available cleared
	  
--	  if (ReadFIFO_Read_Ptr = ReadFIFO_Read_Ptr) then		-- 092017
--	    RX_FIFO_Empty <= '1';	-- don't allow driver to read packet until fully loaded
--	  else
--	    RX_FIFO_Empty <= '0';  */
--	  end if ;
	  
	end if ;
  end process;
 
  ReadFIFO_SM2 : process (irx_fifo_rst, RX_FIFO_rd_clk)
  begin
    if (irx_fifo_rst = '1') then
	  ReadFIFO_Read_Ptr  <= (others => '0');
	elsif (rising_edge(RX_FIFO_rd_clk)) then 
	  if (done_w_active_rx_FIFO_en_d(2) = '1') then  -- current RX FIFO now read out
	    ReadFIFO_Read_Ptr <= ReadFIFO_Read_Ptr + '1';
	  else
	    ReadFIFO_Read_Ptr <= ReadFIFO_Read_Ptr ;
	  end if ;	
    end if ;
  end process;
  
  ReadFIFO_WE : process (ReadFIFO_Write_Ptr,RX_FIFO_wr_en)
  begin
    if (ReadFIFO_Write_Ptr = 0) then
	  iRX_FIFO_wr_en <= b"000" & RX_FIFO_wr_en;
	elsif (ReadFIFO_Write_Ptr = 1) then
	  iRX_FIFO_wr_en <= b"00" & RX_FIFO_wr_en & b"0";
	elsif (ReadFIFO_Write_Ptr = 2) then
	  iRX_FIFO_wr_en <= b"0" & RX_FIFO_wr_en & b"00";
    else 
	  iRX_FIFO_wr_en <= RX_FIFO_wr_en & b"000";
    end if ;
  end process;

  
  Packet_Available_Clear : process (irx_fifo_rst, clk16x)	-- metastability because crossing clock domains
  begin
    if (irx_fifo_rst = '1') then
      packet_available_clear_reg <= (others => '0');
	elsif (rising_edge(clk16x)) then
	  packet_available_clear_reg(2 downto 0) <= packet_available_clear_reg(1 downto 0) & rx_packet_avail_int;
	else
	  packet_available_clear_reg <= packet_available_clear_reg; 
    end if ;
  end process;
  
 
  Done_w_pkt : process (irx_fifo_rst, RX_FIFO_rd_clk)
  begin
    if (irx_fifo_rst = '1') then
	  done_w_active_rx_FIFO_en_d <= (others => '0');
	elsif (rising_edge(RX_FIFO_rd_clk)) then
	  done_w_active_rx_FIFO_en_d <= done_w_active_rx_FIFO_en_d(1 downto 0) & done_w_active_rx_FIFO_en;
	else
	  done_w_active_rx_FIFO_en_d <= done_w_active_rx_FIFO_en_d; 
    end if ;
  end process;
  
--  
--
--
  
  FIFO_READ_SEL : process (ReadFIFO_Read_Ptr,RX_FIFO_rd_en,RX_FIFO_DOUT_0,iRX_FIFO_Empty,iRX_FIFO_Full, iRX_FIFO_OVERFLOW,iRX_FIFO_UNDERRUN,
  RX_FIFO_DOUT_1,RX_FIFO_DOUT_2,RX_FIFO_DOUT_3,RX_FIFO_Reset_v,irx_fifo_rst,done_w_active_rx_FIFO_en_d)
  
    begin
	  if (irx_fifo_rst = '1') then
	    RX_FIFO_Reset_v(3 downto 0) <= b"1111";
	  else
	    case ReadFIFO_Read_Ptr is
	      when b"00" => 
		    iRX_FIFO_rd_en  <= (3|2|1 => '0',0 => RX_FIFO_rd_en);
		    RX_FIFO_DOUT <= RX_FIFO_DOUT_0;      
		    RX_FIFO_Empty <= iRX_FIFO_Empty(0);		-- 092017  
		    RX_FIFO_Full <= iRX_FIFO_Full(0);
		    RX_FIFO_OVERFLOW <= iRX_FIFO_OVERFLOW(0);
		    RX_FIFO_UNDERRUN <= iRX_FIFO_UNDERRUN(0);  
		    RX_FIFO_Reset_v(3 downto 0) <= b"000" &  done_w_active_rx_FIFO_en_d(0);
		  when b"01" => 
		    iRX_FIFO_rd_en  <= (3|2|0 => '0',1 => RX_FIFO_rd_en);
		    RX_FIFO_DOUT <= RX_FIFO_DOUT_1;    
		    RX_FIFO_Empty <= iRX_FIFO_Empty(1);		
		    RX_FIFO_Full <= iRX_FIFO_Full(1);
		    RX_FIFO_OVERFLOW <= iRX_FIFO_OVERFLOW(1);
		    RX_FIFO_UNDERRUN <= iRX_FIFO_UNDERRUN(1); 
		    RX_FIFO_Reset_v(3 downto 0) <= b"00" &  done_w_active_rx_FIFO_en_d(0) & '0';		  
		  when b"10" => 
   	        iRX_FIFO_rd_en  <= (3|1|0 => '0',2 => RX_FIFO_rd_en);
		    RX_FIFO_DOUT <= RX_FIFO_DOUT_2;      
		    RX_FIFO_Empty <= iRX_FIFO_Empty(2);
		    RX_FIFO_Full <= iRX_FIFO_Full(2);
		    RX_FIFO_OVERFLOW <= iRX_FIFO_OVERFLOW(2);
		    RX_FIFO_UNDERRUN <= iRX_FIFO_UNDERRUN(2);     
		    RX_FIFO_Reset_v(3 downto 0) <= '0' &  done_w_active_rx_FIFO_en_d(0) & b"00";
		  when b"11" => 
		    iRX_FIFO_rd_en  <= (2|1|0 => '0',3 => RX_FIFO_rd_en);
		    RX_FIFO_DOUT <= RX_FIFO_DOUT_3;    
		    RX_FIFO_Empty <= iRX_FIFO_Empty(3);		
		    RX_FIFO_Full <= iRX_FIFO_Full(3);
		    RX_FIFO_OVERFLOW <= iRX_FIFO_OVERFLOW(3);
		    RX_FIFO_UNDERRUN <= iRX_FIFO_UNDERRUN(3);   
		    RX_FIFO_Reset_v(3 downto 0) <=  done_w_active_rx_FIFO_en_d(0) & b"000";		  
		  when others =>
		    null;
	    end case;			
	  end if;
    end process;  	
	
	
-- debug logic
	
	  
  FIFO_Debug1 : process (irx_fifo_rst, clk16x)
  begin
    if (irx_fifo_rst = '1') then
      iFIFO_Ptr_Err <= '0';
	elsif (rising_edge(clk16x)) then 
	  if (ReadFIFO_Write_Ptr = 0 and ReadFIFO_Read_Ptr = 0) then -- pass
	    iFIFO_Ptr_Err <='0';
	  elsif (ReadFIFO_Write_Ptr = 1 and ReadFIFO_Read_Ptr = 0) then -- pass
	    iFIFO_Ptr_Err <='0';
	  elsif (ReadFIFO_Write_Ptr = 2 and ReadFIFO_Read_Ptr = 0) then -- pass
	    iFIFO_Ptr_Err <= '0';
	  elsif (ReadFIFO_Write_Ptr = 3 and ReadFIFO_Read_Ptr = 0) then -- pass
	    iFIFO_Ptr_Err <= '0';
	  elsif (ReadFIFO_Write_Ptr = 0 and ReadFIFO_Read_Ptr = 1) then -- pass
	    iFIFO_Ptr_Err <= '0';
	  elsif (ReadFIFO_Write_Ptr = 0 and ReadFIFO_Read_Ptr = 2) then -- pass
	    iFIFO_Ptr_Err <= '0';
	  elsif (ReadFIFO_Write_Ptr = 0 and ReadFIFO_Read_Ptr = 3) then -- pass
	    iFIFO_Ptr_Err <= '0';
	  else
	    iFIFO_Ptr_Err <= '1';
	  end if;
	end if;
  end process;  
  
  
end Behavioral;
