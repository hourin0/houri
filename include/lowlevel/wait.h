U0 wait_for_io(UI32 timer);
U0 sleep(UI32 time);

U0 wait_for_io(UI32 timer) {
	while (timer>0) {
		__asm__ volatile("nop");
		timer--;
	}
}
U0 sleep(UI32 time) {
	wait_for_io(time);
}
