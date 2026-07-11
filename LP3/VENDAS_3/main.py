import tkinter as tk

from Produtos import Produto
from Persistencia import Persistencia
from TelaPrincipal import TelaPrincipal

def iniciar_interface():
    persistenciaProdutos = Persistencia("produtos.pkl")
    produtos = persistenciaProdutos.carregar([])

    janela = tk.Tk()
    janela.title("Sistema de Vendas")
    janela.geometry("1200x700")
    janela.configure(bg="#D6E4B0")

    TelaPrincipal(janela, produtos, persistenciaProdutos)

    janela.mainloop()



if __name__ == "__main__":
    iniciar_interface()
