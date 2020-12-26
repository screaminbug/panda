static int suzuki_rx_hook(CAN_FIFOMailBox_TypeDef *to_push) {
  UNUSED(to_push);
  // TODO
  return true;
}

static int suzuki_tx_hook(CAN_FIFOMailBox_TypeDef *to_send) {
  // TODO: process samples for safety.
  // 1 allows the message through
  UNUSED(to_send);
  return false; // don't allow anything (last time power steering failed)
}

static void suzuki_init(int16_t param) {
  UNUSED(param);
  controls_allowed = false;   // TODO
}

const safety_hooks suzuki_hooks = {
  .init = suzuki_init,
  .rx = suzuki_rx_hook,
  .tx = suzuki_tx_hook,
  .tx_lin = nooutput_tx_lin_hook,
  .fwd = default_fwd_hook,
};

