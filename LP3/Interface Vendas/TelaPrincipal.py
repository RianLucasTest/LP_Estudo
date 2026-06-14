import tkinter as tk


class TelaPrincipal(tk.Frame):

    def __init__(self, pai, app):

        super().__init__(pai)
        self.app = app

        self.config(bg="#507C60")

        tk.Label(
            self,
            text="Sistema de Vendas", 
            font=("arial", 25, "bold"), 
            bg="#507C60", 
            fg="#FFFFFF"
        ).pack(pady=(60, 80))

        botoes = [
            ("Cadastrar", "cadastra"),
            ("But2", "comando2"),
            ("But3", "comando3"),
            ("But4", "comando4"),
            ("But5", "comando5"),
            ("But6", "comando6")
        ]

        for i in range(0, len(botoes), 2):
            butBox = tk.Frame(self, bg="#507C60")
            butBox.pack(pady=10)

            for nome, novap in botoes[i:i+2]:
                tk.Button(
                    butBox, 
                    text=nome, 
                    font=("arial", 15), 
                    bg="#75B495",
                    command = lambda d=novap:
                    self.app.trocaPag(d)
                ).pack(side="left", padx=10)