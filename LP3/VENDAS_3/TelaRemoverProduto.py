import tkinter as tk
from tkinter import messagebox


class TelaRemoverProduto(tk.Toplevel):
    def __init__(self, janela, produtos, persistenciaProdutos, atualizarLista):
        super().__init__(janela)
        self.title("Remover Produto")
        self.geometry("300x180")
        self.configure(bg="white")

        self.produtos = produtos
        self.persistenciaProdutos = persistenciaProdutos
        self.atualizarLista = atualizarLista

        tk.Label(
            self, text="Codigo do produto", bg="white", font=("Arial", 12)
        ).pack(pady=(20, 0))
        self.leCodigo = tk.Entry(self)
        self.leCodigo.pack(fill="x", padx=20)

        tk.Button(
            self, text="Remover", font=("Arial", 14),
            command=self.remover
        ).pack(pady=20)

    def remover(self):
        codigoTexto = self.leCodigo.get().strip()

        if not codigoTexto:
            messagebox.showwarning("Atencao", "Informe o codigo!")
            return

        try:
            codigo = int(codigoTexto)
        except ValueError:
            messagebox.showerror("Erro", "Codigo deve ser um numero inteiro!")
            return

        for prod in self.produtos:
            if prod.codigo == codigo:
                self.produtos.remove(prod)
                self.persistenciaProdutos.salvar(self.produtos)
                self.atualizarLista()
                messagebox.showinfo("Sucesso", "Produto removido com sucesso!")
                self.destroy()
                return

        messagebox.showerror("Erro", "Produto nao encontrado!")
