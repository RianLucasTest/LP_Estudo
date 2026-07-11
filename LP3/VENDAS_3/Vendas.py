class Venda:
    def __init__(self, num):
        self.num = num
        self.itens = []
        self.logs = []

    def inserir_item(self, item):
        self.itens.append(item)
        self.addLog(f"Item {item.produto.nome} (cod. {item.produto.codigo}) "
                    f"x{item.qtd} inserido na venda {self.num}")

    def excluir_item(self, codigo):
        for item in self.itens:
            if item.produto.codigo == codigo:
                item.produto.novoEstoque(item.produto.estoque + item.qtd)
                self.itens.remove(item)
                self.addLog(f"Item {item.produto.nome} (cod. {item.produto.codigo}) "
                            f"removido da venda {self.num}")
                return True
        return False

    def calc_total(self):
        soma = 0
        for item in self.itens:
            soma += item.subtotal()
        return round(soma, 2)

    def addLog(self, msg):
        if msg == "":
            return
        self.logs.append(msg)

    def clearLog(self):
        self.logs = []

    def relatorio(self):
        linhas = []
        linhas.append("=" * 16 + "RELATORIO" + "=" * 15)
        for msg in self.logs:
            linhas.append(f"|{msg}")
        linhas.append("=" * 44)
        return "\n".join(linhas)

    def print_venda(self):
        linhas = []
        linhas.append("=" * 40)
        linhas.append(f"Venda numero {self.num}")
        linhas.append("=" * 40)

        for item in self.itens:
            linhas.append("-" * 30)
            linhas.append(item.printItem())
            linhas.append("-" * 30)

        linhas.append(f"TOTAL: {self.calc_total():.2f}")
        linhas.append("=" * 40)
        return "\n".join(linhas)
