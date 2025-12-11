from flask import Flask, request, jsonify
from flask_cors import CORS
import serial, time

SERIAL_PORT = 'com5'
BAUD = 9600

arduino = serial.Serial(SERIAL_PORT, BAUD, timeout = 1)
time.sleep(2)

app = Flask(__name__)
CORS(app) # 다른 출처(파일/로컬 서버)에서 접근 허용
state = "off"

@app.post("/led")
def led():
    global state
    data = request.get_json(force=True)
    desired = data.get("state")

    if desired == "on":
        arduino.write(b'1')
        state = "on"
    elif desired == "off":
        arduino.write(b'0')
        state = "off"
    else:
        return jsonify({"ok": False, "error": "state must be 'on' or 'off'"}), 400
    return jsonify({"ok": True, "state": state})

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000, debug=True, use_reloader=False, threaded=False)
