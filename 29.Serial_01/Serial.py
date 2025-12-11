import serial
import time

arduino = serial.Serial('com5', 9600)
time.sleep(1)

print("'1'을 입력하면 LED ON & '0'을 입력하면 LED OFF")
print("다른 걸 입력하면 python 프로그램 종료")

while 1:
    var = input() # 터미널에서 입력된 문자열 입력하는 곳

    if var == '1':
        var = var.encode("utf-8") # 아두이노에 값을 전달하기 위해 바이트 형식으로 인코딩
        arduino.write(var) # 아두이노에 바이트 형식으로 변환된 '1'을 보냄
        print("LED ON")
        time.sleep(1)
    elif var == '0':
        var = var.encode('utf-8')
        arduino.write(var)
        print("LED OFF")
        time.sleep(1)
    else:
        break