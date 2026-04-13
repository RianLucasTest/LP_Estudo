from winotify import Notification, audio
import winsound
import time

time.sleep(10)

toast = Notification(app_id="Python",
                     title="SISTEMA",
                     msg="VOCÊ LIGOU O SISTEMA, OBRIGADO <3!!\n\n\n<3",
                     duration="long")

path = r"C:\Users\User\Desktop\Teste noti\somTeste.wav"
path_cabra = r"C:\Users\User\Desktop\Teste noti\cabra.wav"


toast.show()
for i in range(0,10):
    winsound.PlaySound(path_cabra, winsound.SND_FILENAME and winsound.SND_ASYNC)
    #toast.set_audio(audio.Sound.Custom(path), loop=True)
    time.sleep(2.5)
