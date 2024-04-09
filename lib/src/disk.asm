extern ata_read
extern ata_write

ata_read:
    push ebp
    mov ebp, esp

    push eax
    push ebx
    push ecx
    push edx
    push edi


    mov eax, DWORD [esp + 4]


    mov ebx, eax ; save LBA address


    ; send bits 24 - 27 of LBA addr
    mov edx, 0x1F6
    shr eax, 24
    or al, 11100000b
    out dx, al

    ; send number of sectors to read
    mov edx, 0x1F2
    mov al, cl
    out dx, al

    ; send bits 0 - 7 of LBA addr
    mov edx, 0x1F3
    mov eax, ebx   ; reload original LBA address
    out dx, al

    ; send bits 8 - 15 of LBA addr
    mov edx, 0x1F4
    mov eax, ebx   ; save original LBA address
    shr eax, 8
    out dx, al

    ; send bits 16 - 23 of LBA addr
    mov edx, 0x1F5
    mov eax, ebx
    shr eax, 16
    out dx, al

    ; write to command port
    mov edx, 0x1F7
    mov al, 0x20
    out dx, al

    still_going:
        in al, dx
        test al, 8
        jz still_going

        mov eax, 256
        xor bx, bx 
        mov bl, cl
        mul bx
        mov ecx, eax
        mov edx, 0x1F0
        rep insw



    pop edi 
    pop edx
    pop ecx
    pop ebx
    pop eax

    pop ebp
    ret