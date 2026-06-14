import tkinter as tk
from PIL import Image, ImageTk

def responde_clique():
    rotuloNome.config(text="")
    rotuloDoenca.config(text="")
    nome.forget()
    doenca.forget()
    butao.forget()
    aviso.config(text="ERRO: Já existe um usuário com esse sintoma!", font=("arial", 25, "bold"))


janela = tk.Tk()
janela.config(bg="#628c8e")
janela.geometry("800x900")
janela.title("Minha janela")

rotulo = tk.Label(janela, text="Ficha Médica", font=("Arial", 40), bg="#628c8e")
rotulo.pack(pady=5)

aviso = tk.Label(janela, text="", font=("Arial", 25), bg="#628c8e", fg="red")
aviso.pack(pady=10)

rotuloNome = tk.Label(janela, text="Insira Seu nome", font=("Arial", 25), bg="#628c8e")
rotuloNome.pack(pady=10)

nome = tk.Entry(janela, font=("arial", 18))
nome.pack()

rotuloDoenca = tk.Label(janela, text="Insira um sintoma", font=("Arial", 25), bg="#628c8e")
rotuloDoenca.pack(pady=10)
doenca = tk.Entry(janela, font=("arial", 18))
doenca.pack()

butao = tk.Button(janela, text="Cadastrar", command=responde_clique, font=("arial", 20), bg="#a9bbb7")
butao.pack(pady=40)


imagem = Image.open("goodDoctor.png")

imagem_redimensionada = imagem.resize((400, 400), Image.Resampling.LANCZOS)

imagemTk = ImageTk.PhotoImage(imagem_redimensionada)

rotuloImg = tk.Label(janela, image=imagemTk)
rotuloImg.pack()


janela.mainloop()
