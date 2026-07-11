import tkinter as tk


class TelaHistorico(tk.Toplevel):
    def __init__(self, janela, venda, persistenciaHistorico):
        super().__init__(janela)
        self.title("Historico / Relatorio")
        self.geometry("520x520")
        self.configure(bg="white")

        frameTexto = tk.Frame(self, bg="white")
        frameTexto.pack(fill="both", expand=True, padx=10, pady=10)
        frameTexto.grid_rowconfigure(0, weight=1)
        frameTexto.grid_columnconfigure(0, weight=1)

        scrollbar = tk.Scrollbar(frameTexto)
        scrollbar.grid(row=0, column=1, sticky="ns")

        self.texto = tk.Text(frameTexto, wrap="word", yscrollcommand=scrollbar.set)
        self.texto.grid(row=0, column=0, sticky="nsew")
        scrollbar.config(command=self.texto.yview)

        self.texto.insert(tk.END, "VENDA ATUAL\n")
        self.texto.insert(tk.END, venda.print_venda() + "\n\n")
        self.texto.insert(tk.END, venda.relatorio() + "\n\n")

        historico = persistenciaHistorico.carregar([])
        if historico:
            self.texto.insert(tk.END, "VENDAS FINALIZADAS ANTERIORMENTE\n")
            for v in historico:
                self.texto.insert(tk.END, v.print_venda() + "\n\n")

        self.texto.config(state="disabled")
