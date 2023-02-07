import speech_recognition as sr
import serial

r = sr.Recognizer() 
arduino = serial.Serial("COM4",9600)
while True:
    with sr.Microphone() as source:
        print('Ingresa comando de voz: ')
        r.adjust_for_ambient_noise(source, duration=1)
        print("Escuchando...")
        audio = r.listen(source, timeout=5)
        print("Accion ejecutada")
        try:
            text = r.recognize_google(audio,language='es-ES')
        except:
            print("",end="")
        if('avanzar' in text or 'adelante' in text ):
            print("avanzar")
            arduino.write(b'a')
        elif('detener' in text or 'detente' in text or 'para' in text): 
            print("detente")
            arduino.write(b's')
        elif('retroceder' in text or 'atrás' in text or 'retro' in text): 
            print("retrocede")
            arduino.write(b'r')
        elif('derecha' in text or 'derechas' in text or 'dere' in text): 
            print("derecha")
            arduino.write(b'd')
        elif('izquierda' in text or 'izquierdas' in text or 'izqui' in text): 
            print("izquierda")
            arduino.write(b'i')
        else:
            print("",end="")