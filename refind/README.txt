Set refind as default boot loader by "bcdedit /set {bootmgr} path \EFI\refind\refind_x64.efi" command will cause the
efi boot loader not work. And it even can't load windows 10 successfully.

Install Ubuntu 16.04, it will install grub2 boot loader in /boot and also install efi
boot loader in /boot/efi(using df -h for detail)
    
Configure refind to double-boot Ubuntu16.04 and windows10 under UEFI:
1. press F9 when booting computer, and enter Ubuntu os vis boot menu.

2. unzip refind-bin-ver_no.zip to refind-bin-ver_no folder
   su -
   cd refind-bin-ver_no
   cp -r refind /boot/efi/EFI/

3. rename /boot/efi/EFI/Microsoft to /boot/efi/EFI/Win10
   rename /boot/efi/EFI/refind to /boot/efi/EFI/Microsoft(trick!!!)

4. copy all contents in /boot/efi/EFI/Win10/Boot to /boot/efi/EFI/Win10
   delete empty folder /boot/efi/EFI/Win10/Boot

5. mkdir Boot in /boot/efi/EFI/Microsoft
   cut-copy all contents in /boot/efi/EFI/Microsoft to /boot/efi/EFI/Microsoft/Boot(treat refind as the default windows efi)
   rename /boot/efi/EFI/Microsoft/Boot/refind_x64.efi to /boot/efi/EFI/Microsoft/Boot/bootmgfw.efi
   rename /boot/efi/EFI/Microsoft/Boot/refind.conf-sample to /boot/efi/EFI/Microsoft/Boot/refind.conf

6. modify the refind.conf file
   6.1 add Ubuntu16.04 and Win10 entries
   6.2 remove duplicate and redundant entries(dont_scan_volumes, dont_scan_dirs, dont_scan_files, showtools)
   6.3 change refind background(banner)
   Note: refer to refind.conf for detail

I have tried the above method and it succeed.
Maybe you can try other method as described in refind-bin-ver_no/docs/refind/Installing.html

