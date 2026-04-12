from vendas import *
from winotify import Notification, audio

toast = Notification(app_id="Python",
                     title="Alerta!",
                     msg="Bobão",
                     duration="long")
toast.show()
toast.set_audio(audio.Default, loop=True)

def main():
    item1 = criaItem("Maçã", 3.5, 1001, 10)
    item2 = criaItem("Banana", 9.2, 1002, 5)
    item3 = criaItem("Frango", 6, 1003, 3)
    venda1=Venda(1)

    venda1.inserir_item(item1)
    venda1.inserir_item(item2)
    venda1.inserir_item(item3)

    venda1.print_venda()

    venda1.excluir_item(item2.produto.codigo)

    venda1.print_venda()

    #item1.printItem()

main()