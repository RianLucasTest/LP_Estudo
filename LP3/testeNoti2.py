from winotify import Notification, audio
import winsound
import time
import os 
import sys

time.sleep(10)

toast = Notification(app_id="Python",
                     title="SISTEMA",
                     msg="VOCÊ LIGOU O SISTEMA, OBRIGADO <3!!\n\n\n<3",
                     duration="long")

path1 = r"C:\Users\User\Desktop\Teste noti\somTeste.wav"
path_cabra = r"C:\Users\User\Desktop\Teste noti\cabra.wav"



def caminho_arquivo(nome):
    if hasattr(sys, '_MEIPASS'):
        base = sys._MEIPASS
    else:
        base = os.path.dirname(__file__)
    return os.path.join(base, nome)

path2 = caminho_arquivo("cabra.wav")

toast.show()
for i in range(0,10):
    winsound.PlaySound(path2, winsound.SND_FILENAME and winsound.SND_ASYNC)
    #toast.set_audio(audio.Sound.Custom(path), loop=True)
    time.sleep(2.5)
