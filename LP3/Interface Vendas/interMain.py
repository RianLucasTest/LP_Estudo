import tkinter as tk
from TelaCadastro import *
from TelaPrincipal import *

class App():
    def __init__(self, janela):

        self.janela = janela
        self.janela.title("Sistema de Vendas")
        self.janela.geometry("800x600")
        self.janela.config(bg="#507C60")

        self.container = tk.Frame(self.janela, background="#507C60")
        self.container.pack(fill="both", expand=True)
        
        self.container.grid_rowconfigure(0, weight=1)
        self.container.grid_columnconfigure(0, weight=1)

        self.pags = {}

        self.initPags()
        self.pags["principal"].tkraise()
    

    def initPags(self):
        self.pags["principal"] = TelaPrincipal(self.container, self)
        self.pags["cadastra"] = CadastraProd(self.container, self)

        for tela in self.pags.values():
            tela.grid(row=0, column=0, sticky="nsew")


    def trocaPag(self, nova):
        self.pags[nova].tkraise()

win = tk.Tk()

App(win)

win.mainloop()