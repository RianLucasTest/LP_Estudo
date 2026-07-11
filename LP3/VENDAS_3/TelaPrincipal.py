import tkinter as tk
from tkinter import messagebox

from Item import Item
from Vendas import Venda
from Persistencia import Persistencia
from TelaCadastroProduto import TelaCadastroProduto
from TelaRemoverProduto import TelaRemoverProduto
from TelaHistorico import TelaHistorico


class TelaPrincipal:
    def __init__(self, janela, produtos, persistenciaProdutos):
        self.janela = janela
        self.produtos = produtos
        self.persistenciaProdutos = persistenciaProdutos
        self.persistenciaHistorico = Persistencia("historico.pkl")

        historico = self.persistenciaHistorico.carregar([])
        proximoNumero = historico[-1].num + 1 if historico else 1
        self.venda = Venda(proximoNumero)

        self.framePrincipal = tk.Frame(janela, bg="#D6E4B0", bd=3, relief="solid")
        self.framePrincipal.pack(fill="both", expand=True, padx=10, pady=10)

        self.framePrincipal.grid_columnconfigure(0, weight=4)
        self.framePrincipal.grid_columnconfigure(1, weight=1)
        self.framePrincipal.grid_columnconfigure(2, weight=4)
        self.framePrincipal.grid_rowconfigure(1, weight=1)

        nomeMercado = tk.Label(
            self.framePrincipal,
            text="Mercadão de Ouro",
            bg="#D6E4B0",
            font=("Arial", 26, "bold")
        )
        nomeMercado.grid(row=0, column=1, pady=15)

        frameProdutos = tk.LabelFrame(
            self.framePrincipal,
            text="Produtos Disponiveis",
            bg="#D6E4B0",
            font=("Arial", 14, "bold")
        )
        frameProdutos.grid(row=1, column=0, padx=10, pady=10, sticky="nsew")
        frameProdutos.grid_rowconfigure(0, weight=1)
        frameProdutos.grid_columnconfigure(0, weight=1)

        self.listaProdutos = tk.Listbox(frameProdutos)
        self.listaProdutos.grid(row=0, column=0, sticky="nsew", padx=5, pady=5)

        frameBotoes = tk.Frame(self.framePrincipal, bg="#D6E4B0")
        frameBotoes.grid(row=1, column=1, padx=15)

        tk.Button(frameBotoes, text="Adicionar produto", width=20, font=("arial", 16),
                  command=self.abrirTelaCadastroProduto).pack(pady=8)
        tk.Button(frameBotoes, text="Remover Produto", width=20, font=("arial", 16),
                  command=self.abrirTelaRemoverProduto).pack(pady=8)
        tk.Button(frameBotoes, text="Finalizar Venda", width=20, font=("arial", 16),
                  command=self.finalizarVenda).pack(pady=8)
        tk.Button(frameBotoes, text="Historico", width=20, font=("arial", 16),
                  command=self.abrirTelaHistorico).pack(pady=8)

        frameVenda = tk.LabelFrame(
            self.framePrincipal,
            text="Venda", 
            bg="#D6E4B0",
            font=("Arial", 14, "bold")
        )
        frameVenda.grid(row=0, column=2, rowspan=3, padx=10, pady=10, sticky="nsew")
        frameVenda.grid_rowconfigure(0, weight=1)
        frameVenda.grid_columnconfigure(0, weight=1)

        self.listaVenda = tk.Listbox(frameVenda)
        self.listaVenda.grid(row=0, column=0, sticky="nsew", padx=5, pady=5)

        self.rotuloTotal = tk.Label(
            frameVenda,
            text="Total a pagar: R$ 0.00", 
            bg="#D6E4B0",
            font=("Arial", 12, "bold"),
            anchor="w"
        )
        self.rotuloTotal.grid(row=1, column=0, padx=5, pady=5, sticky="w")

        frameItens = tk.Frame(self.framePrincipal, bg="#D6E4B0")
        frameItens.grid(row=2, column=0, columnspan=2, padx=10, pady=10, sticky="nsew")
        frameItens.grid_columnconfigure(0, weight=2)
        frameItens.grid_columnconfigure(1, weight=1)

        frameAdicionar = tk.LabelFrame(
            frameItens,
            text="ADICIONAR ITEM A VENDA", 
            bg="#D6E4B0",
            font=("Arial", 12, "bold")
        )
        frameAdicionar.grid(row=0, column=0, padx=(0, 10), sticky="nsew")

        tk.Label(frameAdicionar, text="Codigo", font=("arial", 12, "bold"), bg="#D6E4B0").pack(padx=10, pady=(10, 0))
        self.leCodigo = tk.Entry(frameAdicionar)
        self.leCodigo.pack(fill="x", padx=10)

        tk.Label(frameAdicionar, text="Quantidade", font=("arial", 14, "bold"), bg="#D6E4B0").pack(padx=10, pady=(10, 0))
        self.leQtd = tk.Entry(frameAdicionar)
        self.leQtd.pack(fill="x", padx=10)

        tk.Button(
            frameAdicionar,
            text="Adicionar item", font=("arial", 14, "bold"),
            command=self.addItem
        ).pack(pady=10)

        frameRemover = tk.LabelFrame(
            frameItens,
            text="REMOVER ITEM DA VENDA", 
            bg="#D6E4B0",
            font=("Arial", 12, "bold")
        )
        frameRemover.grid(row=0, column=1, sticky="nsew")

        tk.Label(frameRemover, text="Codigo", font=("arial", 14, "bold"), bg="#D6E4B0").pack(anchor="w", padx=10, pady=(10, 0))
        self.codigoRemover = tk.Entry(frameRemover)
        self.codigoRemover.pack(fill="x", padx=10)

        tk.Button(
            frameRemover,
            text="Remover item", font=("arial", 14, "bold"),
            command=self.removerItem
        ).pack(pady=10)

        self.atualizarListaProdutos()
        self.atualizarListaVenda()
        self.janela.protocol("WM_DELETE_WINDOW", self.fecharJanela)

    def atualizarListaProdutos(self):
        self.listaProdutos.delete(0, tk.END)
        for prod in self.produtos:
            linha = f"{prod.codigo} - {prod.nome} - R$ {prod.preco:.2f} - Estoque: {prod.estoque}"
            self.listaProdutos.insert(tk.END, linha)
            aviso = prod.verifEstoque()
            if aviso:
                self.listaProdutos.insert(tk.END, f"     Aviso: {aviso}")

    def atualizarListaVenda(self):
        self.listaVenda.delete(0, tk.END)
        for item in self.venda.itens:
            linha = (f"{item.produto.codigo} - {item.produto.nome} "
                     f"x{item.qtd} = R$ {item.subtotal():.2f}")
            self.listaVenda.insert(tk.END, linha)
        self.rotuloTotal.config(text=f"Total a pagar: R$ {self.venda.calc_total():.2f}")

    def addItem(self):
        codigoTexto = self.leCodigo.get().strip()
        qtdTexto = self.leQtd.get().strip()

        if not codigoTexto or not qtdTexto:
            messagebox.showwarning("Atencao", "Informe o codigo e a quantidade!")
            return

        try:
            codigoAdd = int(codigoTexto)
            qtdItem = int(qtdTexto)
        except ValueError:
            messagebox.showerror("Erro", "Codigo e quantidade devem ser numeros inteiros!")
            return

        for prod in self.produtos:
            if codigoAdd == prod.codigo:
                try:
                    item = Item(prod, qtdItem)
                except ValueError as erro:
                    messagebox.showerror("Erro", str(erro))
                    return

                self.venda.inserir_item(item)
                self.persistenciaProdutos.salvar(self.produtos)
                self.leCodigo.delete(0, tk.END)
                self.leQtd.delete(0, tk.END)
                self.atualizarListaVenda()
                self.atualizarListaProdutos()
                return

        messagebox.showerror("Erro", "Produto nao encontrado no estoque!")

    def removerItem(self):
        codigoTexto = self.codigoRemover.get().strip()

        if not codigoTexto:
            messagebox.showwarning("Atencao", "Informe o codigo do item a remover!")
            return

        try:
            codigoRemove = int(codigoTexto)
        except ValueError:
            messagebox.showerror("Erro", "Codigo deve ser um numero inteiro!")
            return

        removido = self.venda.excluir_item(codigoRemove)
        self.codigoRemover.delete(0, tk.END)

        if removido:
            self.persistenciaProdutos.salvar(self.produtos)
            self.atualizarListaVenda()
            self.atualizarListaProdutos()
        else:
            messagebox.showerror("Erro", "Produto nao encontrado na venda!")

    def finalizarVenda(self):
        if not self.venda.itens:
            messagebox.showwarning("Atencao", "Nao ha itens na venda!")
            return

        total = self.venda.calc_total()
        self.venda.addLog(f"Valor total da venda {self.venda.num}: {total:.2f}")

        historico = self.persistenciaHistorico.carregar([])
        historico.append(self.venda)
        self.persistenciaHistorico.salvar(historico)
        self.persistenciaProdutos.salvar(self.produtos)

        messagebox.showinfo(
            "Venda finalizada",
            f"Venda {self.venda.num} finalizada!\nTotal: R$ {total:.2f}"
        )

        self.venda = Venda(self.venda.num + 1)
        self.atualizarListaVenda()
        self.atualizarListaProdutos()

    def abrirTelaCadastroProduto(self):
        TelaCadastroProduto(
            self.janela, self.produtos, self.persistenciaProdutos,
            self.atualizarListaProdutos
        )

    def abrirTelaRemoverProduto(self):
        TelaRemoverProduto(
            self.janela, self.produtos, self.persistenciaProdutos,
            self.atualizarListaProdutos
        )

    def abrirTelaHistorico(self):
        TelaHistorico(self.janela, self.venda, self.persistenciaHistorico)

    def fecharJanela(self):
        self.finalizarVenda()
        self.janela.destroy()
