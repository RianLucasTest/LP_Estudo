import tkinter as tk
from tkinter import messagebox

from Produtos import Produto


class TelaCadastroProduto(tk.Toplevel):
    def __init__(self, janela, produtos, persistenciaProdutos, atualizarLista):
        super().__init__(janela)
        self.title("Cadastrar Produto")
        self.geometry("350x420")
        self.configure(bg="white")

        self.produtos = produtos
        self.persistenciaProdutos = persistenciaProdutos
        self.atualizarLista = atualizarLista

        tk.Label(self, text="Nome", bg="white", font=("Arial", 12)).pack(pady=(15, 0))
        self.leNome = tk.Entry(self)
        self.leNome.pack(fill="x", padx=20)

        tk.Label(self, text="Preco", bg="white", font=("Arial", 12)).pack(pady=(10, 0))
        self.lePreco = tk.Entry(self)
        self.lePreco.pack(fill="x", padx=20)

        tk.Label(self, text="Codigo", bg="white", font=("Arial", 12)).pack(pady=(10, 0))
        self.leCodigo = tk.Entry(self)
        self.leCodigo.pack(fill="x", padx=20)

        tk.Label(self, text="Estoque inicial", bg="white", font=("Arial", 12)).pack(pady=(10, 0))
        self.leEstoque = tk.Entry(self)
        self.leEstoque.pack(fill="x", padx=20)

        tk.Label(self, text="Estoque ideal", bg="white", font=("Arial", 12)).pack(pady=(10, 0))
        self.leEstoqueIdeal = tk.Entry(self)
        self.leEstoqueIdeal.pack(fill="x", padx=20)

        tk.Button(
            self, text="Cadastrar", font=("Arial", 14),
            command=self.cadastrar
        ).pack(pady=20)

    def cadastrar(self):
        nome = self.leNome.get().strip()
        precoTexto = self.lePreco.get().strip()
        codigoTexto = self.leCodigo.get().strip()
        estoqueTexto = self.leEstoque.get().strip()
        estoqueIdealTexto = self.leEstoqueIdeal.get().strip()

        if not all([nome, precoTexto, codigoTexto, estoqueTexto, estoqueIdealTexto]):
            messagebox.showwarning("Atencao", "Preencha todos os campos!")
            return

        try:
            preco = float(precoTexto)
            codigo = int(codigoTexto)
            estoque = int(estoqueTexto)
            estoqueIdeal = int(estoqueIdealTexto)
        except ValueError:
            messagebox.showerror("Erro", "Preco, codigo e estoques devem ser numericos!")
            return

        for prod in self.produtos:
            if prod.codigo == codigo:
                messagebox.showerror("Erro", "Ja existe um produto com esse codigo!")
                return

        novoProduto = Produto(nome, preco, codigo, estoqueIdeal, estoque)
        self.produtos.append(novoProduto)
        self.persistenciaProdutos.salvar(self.produtos)

        self.atualizarLista()
        messagebox.showinfo("Sucesso", "Produto cadastrado com sucesso!")
        self.destroy()
