import tkinter as tk
from ..ProdutoModular.Item import *
from ..ProdutoModular.Vendas import *
from ..ProdutoModular.Produtos import *

class TelaPrincipal(tk.Frame):
    def __init__(self, master):
        super().__init__(master, bg="#507C60")
        self.pack(fill="both", expand=True)

        self.vendas = Venda(1)
        self.prods = []

        
        self.framePrincipal = tk.Frame(self, bg="white", bd=3, relief="solid")
        self.framePrincipal.pack(fill="both", expand=True, padx=10, pady=10)


        self.framePrincipal.grid_columnconfigure(0, weight=4)
        self.framePrincipal.grid_columnconfigure(1, weight=1)
        self.framePrincipal.grid_columnconfigure(2, weight=4)

        self.framePrincipal.grid_rowconfigure(1, weight=1)

        nomeMercado = tk.Label(
            self.framePrincipal,
            text="Nome do mercado",
            bg="white",
            font=("Arial", 22)
        )
        nomeMercado.grid(row=0, column=1, pady=15)
        

        frameProdutos = tk.LabelFrame(
            self.framePrincipal,
            text="Produtos Disponíveis",
            bg="white",
            font=("Arial", 14)
        )
        frameProdutos.grid(row=1, column=0, padx=10, pady=10, sticky="nsew")

        frameProdutos.grid_rowconfigure(0, weight=1)
        frameProdutos.grid_columnconfigure(0, weight=1)

        self.listaProdutos = tk.Listbox(frameProdutos)
        self.listaProdutos.grid(row=0, column=0, sticky="nsew", padx=5, pady=5)

        '''
        for i in range(20):
            self.listaProdutos.insert(tk.END, f"Produto {i+1}")
        '''

        frameBotoes = tk.Frame(self.framePrincipal, bg="white")
        frameBotoes.grid(row=1, column=1, padx=15)

        tk.Button(frameBotoes, text="Adicionar produto", width=20, font=("arial", 16)).pack(pady=8)
        tk.Button(frameBotoes, text="Remover Produto", width=20, font=("arial", 16)).pack(pady=8)
        tk.Button(frameBotoes, text="Finalizar Venda", width=20, font=("arial", 16)).pack(pady=8)
        tk.Button(frameBotoes, text="Histórico", width=20, font=("arial", 16)).pack(pady=8)



        frameVenda = tk.LabelFrame(
            self.framePrincipal,
            text="Venda",
            bg="white",
            font=("Arial", 14)
        )
        frameVenda.grid(row=0, column=2, rowspan=3,
                             padx=10, pady=10, sticky="nsew")

        frameVenda.grid_rowconfigure(0, weight=1)
        frameVenda.grid_columnconfigure(0, weight=1)

        self.listaVenda = tk.Listbox(frameVenda)
        self.listaVenda.grid(row=0, column=0, sticky="nsew", padx=5, pady=5)

        self.rotuloTotal = tk.Label(
            frameVenda,
            text="Total a pagar: R$ 0,00",
            bg="white",
            font=("Arial", 12),
            anchor="w"
        )
        self.rotuloTotal.grid(row=1, column=0, padx=5, pady=5)


        frameItens = tk.Frame(self.framePrincipal, bg="white")
        frameItens.grid(row=2, column=0, columnspan=2,
                                padx=10, pady=10, sticky="nsew")

        frameItens.grid_columnconfigure(0, weight=2)
        frameItens.grid_columnconfigure(1, weight=1)


        frameAdicionar = tk.LabelFrame(
            frameItens,
            text="ADICIONAR ITEM À VENDA",
            bg="white",
            font=("Arial", 12, "bold")
        )
        frameAdicionar.grid(row=0, column=0, padx=(0,10), sticky="nsew")

        tk.Label(frameAdicionar, text="Código", bg="white").pack(padx=10, pady=(10,0))
        self.leCodigo = tk.Entry(frameAdicionar)
        self.leCodigo.pack(fill="x", padx=10)

        tk.Label(frameAdicionar, text="Quantidade", bg="white").pack(padx=10, pady=(10,0))
        self.leQtd = tk.Entry(frameAdicionar)
        self.leQtd.pack(fill="x", padx=10)

        tk.Button(
            frameAdicionar,
            text="Adicionar item", font=("arial", 14), 
            command = self.addItem
        ).pack(pady=10)



        frameRemover = tk.LabelFrame(
            frameItens,
            text="REMOVER ITEM DA VENDA",
            bg="white",
            font=("Arial", 12)
        )
        frameRemover.grid(row=0, column=1, sticky="nsew")

        tk.Label(frameRemover, text="Código", bg="white").pack(anchor="w", padx=10, pady=(10,0))
        self.codigoRemover = tk.Entry(frameRemover)
        self.codigoRemover.pack(fill="x", padx=10)

        tk.Button(
            frameRemover,
            text="Remover item", font=("arial", 14)
        ).pack(pady=10)

    def addItem(self):
        codigoAdd = self.leCodigo.get()
        self.leCodigo.delete(0, tk.END)
        qtdItem = self.leQtd.get()
        self.leQtd.delete(0, tk.END)

        for prod in self.produtos:
            if codigoAdd == prod.codigo:
                item = Item(prod, qtdItem)
                self.vendas.inserir_item(item)
                self.listaVenda.insert(tk.END)
                self.rotuloTotal.config(text=f"Total a pagar: {self.vendas.calc_total()}")

                break
        else:
            print("Produto n encontrado")


        




janela = tk.Tk()
janela.title("Sistema de Vendas")
janela.geometry("1200x700")
janela.configure(bg="#507C60")

TelaPrincipal(janela)

janela.mainloop()