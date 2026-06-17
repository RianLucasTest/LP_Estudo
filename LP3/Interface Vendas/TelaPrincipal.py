import tkinter as tk


class TelaPrincipal(tk.Frame):

    def __init__(self, pai, app):

        super().__init__(pai)
        self.app = app

        self.config(bg="#507C60")

        tk.Label(
            self,
            text="Sistema de Vendas", 
            font=("arial", 40, "bold"), 
            bg="#507C60", 
            fg="#152C1B"
        ).pack(pady=(150, 120))

        botoes = [
            ("Abrir Venda", "comando1"),
            ("Editar Venda", "comando2"),
            ("Cadastrar", "cadastra"),
            ("Remover Produto", "comando4"),
            ("Mostrar Produtos", "comando5"),
            ("Encerrar Sessão", "comando6")
        ]

        for i in range(0, len(botoes), 2):
            butBox = tk.Frame(self, bg="#507C60")
            butBox.pack(pady=15)

            for nome, novap in botoes[i:i+2]:
                tk.Button(
                    butBox, 
                    text=nome, 
                    font=("arial", 20), 
                    bg="#75B495",
                    width=20,
                    command = lambda d=novap:
                    self.app.trocaPag(d)
                ).pack(side="left", padx=40)