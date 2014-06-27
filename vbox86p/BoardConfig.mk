include $(GENERIC_X86_CONFIG_MK)
TARGET_HAS_THIRD_PARTY_APPS := true
BOARD_USES_TSLIB := false
BOARD_WPA_SUPPLICANT_DRIVER := WIRED
WPA_SUPPLICANT_VERSION      := VER_0_6_X
BOARD_WLAN_DEVICE           := eth1
BUILD_EMULATOR_OPENGL:=true
TARGET_ARCH_VARIANT := x86
TARGET_ARCH := x86
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 1048576000
BOARD_USERDATAIMAGE_PARTITION_SIZE := 4194304000
BOARD_FLASH_BLOCK_SIZE := 512
BOARD_CACHEIMAGE_PARTITION_SIZE := 268435456
BOARD_CACHEIMAGE_FILE_SYSTEM_TYPE := ext4
BOARD_USES_GENERIC_AUDIO := false
BOARD_USES_ALSA_AUDIO := true
BUILD_WITH_ALSA_UTILS := true
TARGET_NO_KERNEL := false
BOARD_KERNEL_CMDLINE := init=/init console=tty0 quiet androidboot.hardware=vbox86 androidboot.console=tty0
TARGET_SHELL := mksh
