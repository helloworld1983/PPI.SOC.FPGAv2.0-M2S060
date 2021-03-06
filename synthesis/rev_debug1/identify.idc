device jtagport builtin
iice new {IICE} -type regular
iice controller -iice {IICE} none
iice sampler -iice {IICE} -depth 4096

signals add -iice {IICE} -silent -trigger -sample  {/rtl/CommsFPGA_top_0/apb3_rdata}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/behavioral/ififo_ptr_err}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/behavioral/irx_fifo_rd_en}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/behavioral/irx_fifo_wr_en}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/behavioral/readfifo_read_ptr}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/behavioral/readfifo_write_ptr}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/rx_fifo_dout}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/rx_fifo_empty}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/rx_fifo_full}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/rx_fifo_overflow}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/rx_fifo_underrun}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/AFE_RX_STATE_MACHINE/behavioral/afe_rx_state}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/MANCHESTER_DECODER_ADAPTER_INST/v1/RX_IDLE_LINE_DETECTOR/behavioral/idle_debug_sm}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/MANCHESTER_DECODER_ADAPTER_INST/v1/RX_IDLE_LINE_DETECTOR/behavioral/idle_line_temp}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/MANCHESTER_DECODER_ADAPTER_INST/v1/RX_IDLE_LINE_DETECTOR/behavioral/prbs_gen_reg0}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/MANCHESTER_DECODER_ADAPTER_INST/v1/RX_IDLE_LINE_DETECTOR/idle_line}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/MANCHESTER_DECODER_ADAPTER_INST/v1/clkdiv}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/MANCHESTER_DECODER_ADAPTER_INST/v1/clock_adjust}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/MANCHESTER_DECODER_ADAPTER_INST/v1/imanches_in_dly}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/MANCHESTER_DECODER_ADAPTER_INST/v1/inrz_data}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/MANCHESTER_DECODER_ADAPTER_INST/v1/manches_in}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/MANCHESTER_DECODER_ADAPTER_INST/v1/manches_in_s}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/MANCHESTER_DECODER_ADAPTER_INST/v1/manchester_in_d}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/MANCHESTER_DECODER_ADAPTER_INST/v1/s2p_data}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/ReadFIFO_Write_SM_PROC/behavioral/readfifo_wr_state}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/ReadFIFO_Write_SM_PROC/behavioral/rx_crc_data_calc}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/ReadFIFO_Write_SM_PROC/rx_crc_error}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/ReadFIFO_Write_SM_PROC/sampler_clk1x_en}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TRANSMIT_SM/behavioral/TX_IDLE_LINE_DETECTOR/behavioral/idle_debug_sm}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TRANSMIT_SM/behavioral/TX_IDLE_LINE_DETECTOR/behavioral/idle_line_temp}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TRANSMIT_SM/behavioral/TX_IDLE_LINE_DETECTOR/behavioral/prbs_gen_reg0}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TRANSMIT_SM/behavioral/TX_IDLE_LINE_DETECTOR/idle_line}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TRANSMIT_SM/behavioral/start_tx_fifo_s}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TRANSMIT_SM/behavioral/tx_idle_line}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TRANSMIT_SM/behavioral/tx_idle_line_s}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TRANSMIT_SM/behavioral/tx_state}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TRANSMIT_SM/byte_clk_en}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TRANSMIT_SM/clk_bit_5mhz}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TRANSMIT_SM/manches_in_dly}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TRANSMIT_SM/start_tx_fifo}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TX_COLLISION_DETECTOR_INST/behavioral/rx_fifo_din_pipe_d1}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TX_COLLISION_DETECTOR_INST/behavioral/sync2rxclk_tx_enable}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TX_COLLISION_DETECTOR_INST/behavioral/sync2rxclk_tx_packet_complt}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TX_COLLISION_DETECTOR_INST/behavioral/tx_fifo_dout_d5_synccompare}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TX_COLLISION_DETECTOR_INST/tx_col_detect_en}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TX_COLLISION_DETECTOR_INST/tx_collision_detect}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/man_data}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/p2s_data}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/apb3_addr}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/apb3_enable}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/apb3_rdata}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/apb3_ready}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/apb3_sel}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/apb3_write}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/INTERRUPT_INST/behavioral/block_int_until_rd}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/INTERRUPT_INST/behavioral/irx_packet_avail_int}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/INTERRUPT_INST/int}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/INTERRUPT_INST/int_reg}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/INTERRUPT_INST/rx_fifo_underrun}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/INTERRUPT_INST/tx_fifo_overflow}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/INTERRUPT_INST/tx_fifo_underrun}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/control_reg}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/int_reg}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/irx_fifo_rd_en}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/itx_fifo_wr_en}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/iup_eop}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/iup_eop_cntdown_en}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/pkt_depth_tx_err}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/rx_packet_depth}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/rx_packet_depth_status}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/status_reg}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/up_eop_sync}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/col_detect}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/int}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/rx_crc_error}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/rx_packet_avail_int}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/rx_packet_complt}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/start_tx_fifo}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/tx_packet_complt}\
{/rtl/CommsFPGA_top_0/behavioral/rx_fifo_din_pipe}\
{/rtl/CommsFPGA_top_0/behavioral/rx_fifo_dout}\
{/rtl/CommsFPGA_top_0/behavioral/rx_fifo_overflow}\
{/rtl/CommsFPGA_top_0/manch_out_p}\
{/rtl/CommsFPGA_top_0/manchester_in}
iice clock -iice {IICE} -edge positive {/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/clk16x}

