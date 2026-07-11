import pickle
import os


class Persistencia:

    def __init__(self, arquivo):
        self.arquivo = arquivo

    def salvar(self, dados):
        with open(self.arquivo, "wb") as f:
            pickle.dump(dados, f)

    def carregar(self, padrao=None):
        if not os.path.exists(self.arquivo):
            return padrao
        try:
            with open(self.arquivo, "rb") as f:
                return pickle.load(f)
        except (EOFError, pickle.UnpicklingError):
            return padrao
