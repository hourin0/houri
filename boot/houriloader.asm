; This bootloader isn't completed yet. At the time writing it only hangs up
; and does nothing. Planned features:
;   Get Memory Map, set up GDT, go to Protected Mode,
;   Detect ACPI/APM
;   Load kernel from disk
;   If I'm feeling happy I can probably make it dualboot

[org 0x7C00]
jmp $

times 510-($-$$)
dw 0xaa55
