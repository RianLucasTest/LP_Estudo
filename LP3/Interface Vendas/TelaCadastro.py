import tkinter as tk

class CadastraProd(tk.Frame):
    def __init__(self, pai, app):
        super().__init__(pai)
        self.app = app

        #self.title("Cadastar Produto")
        #self.geometry("800x450")
        self.config(bg="#507C60")

        tk.Label(
            self, text="Cadastrar Novo Produto", 
            font=("arial", 25, "bold"), 
            fg="#FFFFFF", ##022E11
            bg="#507C60"
        ).pack(pady=50)

        frame = tk.Frame(self, bg="#507C60")
        frame.pack(pady=10)

        campos = [
            "Nome do Produto",
            "Preço do Produto",
            "Código do Produto"
        ]
        self.valores = {
            "nome" : 0,
            "preco" : 0,
            "codigo" : 0,
        }

        for i in range(0, len(campos)):
            texto = campos[i]
            tk.Label(
                frame, text=texto,
                font=("arial", 20, "bold"), 
                fg="#022E11", bg="#507C60"
            ).grid(
                row = i, column=2, 
                padx=(0, 5), pady=(0, 20), 
                sticky="w"
            )

        count=0
        for i in self.valores:
            self.valores[i] = tk.Entry(frame, font=("arial", 12), width=30)
            self.valores[i].grid(row = count, column=3, pady=(0, 15))
            count += 1



        tk.Button(
            frame, text="Voltar", 
            font=("arial", 19, "bold"), 
            fg="#FAEDCD", bg="#344E41", 
            activebackground="#5E756A", 
            activeforeground="#FAEDCD",
            command=lambda: self.app.trocaPag("principal")
        ).grid(
            row=4, column=2, pady=(80, 0)
        )
        
        tk.Button(
            frame, text="Cadastrar", 
            font=("arial", 19, "bold"), 
            fg="#FAEDCD", bg="#344E41", 
            activebackground="#5E756A", 
            activeforeground="#FAEDCD"
        ).grid(
            row=4, column=3, pady=(80, 0)
        )