device jtagport builtin
iice new {IICE} -type regular
iice controller -iice {IICE} none
iice sampler -iice {IICE} -depth 4096

signals add -iice {IICE} -silent -trigger -sample  {/rtl/CommsFPGA_top_0/bd_resetn}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/behavioral/irx_fifo_empty}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/behavioral/irx_fifo_full}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/behavioral/irx_fifo_rst}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/behavioral/itx_fifo_empty}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/behavioral/itx_fifo_rst}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/behavioral/packet_available_clear_reg}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/behavioral/readfifo_read_ptr}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/behavioral/readfifo_write_ptr}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/rx_fifo_empty}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/rx_fifo_full}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/rx_fifo_overflow}\
{/rtl/CommsFPGA_top_0/behavioral/FIFOS_INST/rx_fifo_underrun}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/AFE_RX_STATE_MACHINE/behavioral/afe_rx_state}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/AFE_RX_STATE_MACHINE/idle_line}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/AFE_RX_STATE_MACHINE/packet_avail}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/AFE_RX_STATE_MACHINE/rx_packet_avail}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/MANCHESTER_DECODER_ADAPTER_INST/v1/RX_IDLE_LINE_DETECTOR/behavioral/idle_line_cntr}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/MANCHESTER_DECODER_ADAPTER_INST/v1/RX_IDLE_LINE_DETECTOR/idle_line}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/MANCHESTER_DECODER_ADAPTER_INST/v1/RX_IDLE_LINE_DETECTOR/tx_enable}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/MANCHESTER_DECODER_ADAPTER_INST/v1/clkdiv}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/MANCHESTER_DECODER_ADAPTER_INST/v1/imanches_in_dly}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/MANCHESTER_DECODER_ADAPTER_INST/v1/inrz_data}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/MANCHESTER_DECODER_ADAPTER_INST/v1/irx_center_sample}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/ReadFIFO_Write_SM_PROC/behavioral/RX_CRC_GEN_INST/crc_en}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/ReadFIFO_Write_SM_PROC/behavioral/RX_CRC_GEN_INST/crc_out}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/ReadFIFO_Write_SM_PROC/behavioral/hold_collision}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/ReadFIFO_Write_SM_PROC/behavioral/irx_fifo_wr_en}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/ReadFIFO_Write_SM_PROC/behavioral/irx_packet_end}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/ReadFIFO_Write_SM_PROC/behavioral/readfifo_wr_state}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/ReadFIFO_Write_SM_PROC/behavioral/rx_crc_lowbyte_en}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/ReadFIFO_Write_SM_PROC/behavioral/rx_inprocess}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/ReadFIFO_Write_SM_PROC/behavioral/sm_advance_i}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/ReadFIFO_Write_SM_PROC/packet_avail}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_DECODER_INST/v1/ReadFIFO_Write_SM_PROC/sampler_clk1x_en}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TRANSMIT_SM/behavioral/TX_IDLE_LINE_DETECTOR/behavioral/idle_line_cntr}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TRANSMIT_SM/behavioral/TX_IDLE_LINE_DETECTOR/idle_line}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TRANSMIT_SM/behavioral/TX_IDLE_LINE_DETECTOR/manches_in_dly}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TRANSMIT_SM/behavioral/TX_IDLE_LINE_DETECTOR/tx_enable}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TRANSMIT_SM/behavioral/start_tx_fifo_s}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TRANSMIT_SM/behavioral/tx_idle_line_s}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TRANSMIT_SM/behavioral/tx_state}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TX_COLLISION_DETECTOR_INST/rx_crc_byte_en}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TX_COLLISION_DETECTOR_INST/tx_col_detect_en}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TX_COLLISION_DETECTOR_INST/tx_collision_detect}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TX_CRC_GEN_INST/clk}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/TX_CRC_GEN_INST/crc_en}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/behavioral/p2s_data}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/manchester_out}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/tx_collision_detect}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/tx_enable}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/tx_fifo_rd_en}\
{/rtl/CommsFPGA_top_0/behavioral/MANCHESTER_ENCODER_INST/tx_preamble}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/apb3_addr}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/apb3_rdata}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/apb3_ready}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/apb3_write}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/INTERRUPT_INST/apb3_reset}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/INTERRUPT_INST/behavioral/block_int_until_rd}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/INTERRUPT_INST/behavioral/int_reg_clr}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/INTERRUPT_INST/behavioral/irx_packet_avail_int}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/INTERRUPT_INST/behavioral/rx_crc_error_int}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/INTERRUPT_INST/behavioral/rx_fifo_overflow_int}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/INTERRUPT_INST/behavioral/rx_fifo_underrun_int}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/INTERRUPT_INST/behavioral/up_eop_del}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/control_reg}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/int_reg}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/rx_packet_depth}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/rx_packet_depth_status}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/status_reg}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/behavioral/up_eop}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/col_detect}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/rx_fifo_empty}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/rx_fifo_full}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/rx_fifo_rd_en}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/rx_packet_complt}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/tx_fifo_empty}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/tx_fifo_full}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/tx_fifo_wr_en}\
{/rtl/CommsFPGA_top_0/behavioral/PROCESSOR_INTERFACE_INST/tx_packet_complt}\
{/rtl/CommsFPGA_top_0/behavioral/bd_reset}\
{/rtl/CommsFPGA_top_0/behavioral/long_reset_cntr}\
{/rtl/CommsFPGA_top_0/behavioral/reset}\
{/rtl/CommsFPGA_top_0/behavioral/rx_fifo_din_pipe}\
{/rtl/CommsFPGA_top_0/drvr_en}\
{/rtl/CommsFPGA_top_0/lock}\
{/rtl/CommsFPGA_top_0/manch_out_p}\
{/rtl/CommsFPGA_top_0/manchester_in}\
{/rtl/CommsFPGA_top_0/sw_reset}
iice clock -iice {IICE} -edge positive {/rtl/CommsFPGA_top_0/clk}
