timer dùng timer2 32bit, 16MHz, PSC=15, ARR=99 -> fset=10kHz
Lưu ý:
bố cục code từ 8 -> 10 file
trên sơ đồ nếu muốn code hãy IN HOA tất cả các chữ, ghi theo tên trên schematic
ví dụ: drv_gpio_set_pin(LED1)
khi đổi chip sửa các file mcu_(stm32)_(gpio).c /.h và interface_(gpio).h ; trong đó (x) thay đổi
gencode cấu hình trên stm32cubemx thoải mái
trong schematic có bao nhiêu chân thì bật hết lên

Các lệnh code cơ bản:
GPIO:

