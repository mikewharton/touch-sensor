import threading
import serial.tools.list_ports
import read_serial_func

def process_data(data):
    return data == "1"

def read_serial_and_update():
    b1 = False
    for data in read_serial_func.read_serial_func(COM_PORT, BAUD_RATE):
        b1 = True if process_data(data) else False
        print(b1)

if __name__ == "__main__":
    COM_PORT = 'COM6'
    BAUD_RATE = 9600

    update_thread = threading.Thread(target=read_serial_and_update)
    update_thread.daemon = True
    update_thread.start()
    update_thread.join()
