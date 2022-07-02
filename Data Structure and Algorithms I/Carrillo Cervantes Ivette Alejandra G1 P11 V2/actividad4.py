"""
CARRILLO CERVANTES IVETTE ALEJANDRA
ESTRUCTURA DE DATOS Y ALGORITMOS - GRUPO 1
"""

def merge(left, right): # FUNCION MERGE
	result = [] # SE CREA UNA LISTA, LA CUAL TENDRÁ EL RESULTADO
	left_idx, right_idx = 0, 0 # SE INICIALIZAN EN CERO LA VARIABLE IZQUIERDA Y DERECHA
	while left_idx < len(left) and right_idx < len(right): 
	# CUANDO IZQUIERSA SEA MENOR QUE EL NUMERO DE ELEMENTOS DE LA LISTA EN LA PARTE IZQUIERDA, Y DERECHA SEA MENOR QUE EL NUMERO DE ELEMENTOS DE LA LISTA EN LA PARTE DERECHA
		if left[left_idx] <= right[right_idx]: # SI IZQUIERDA EN SU PRIMER INDICE ES MENOR O IGUAL QUE DERECHA EN SU PRIMER INDICE
			result.append(left[left_idx]) # SE AGREGARA A LA LISTA "result" EL INDICE PRIMERO
			left_idx += 1 # AUMENTARA EL CONTEO DEL INDICE IZQUIERDO
		else: # EN CASO CONTRARIO
			result.append(right[right_idx]) # SE AGREGARA A LA LISTA "result" EL INDICE PRIMERO
			right_idx += 1 # AUMENTARA EL CONTEO DEL INDICE DERECHO
	if left: # SI
		result.extend(left[left_idx:]) # SE AGREGA A LA LISTA "result" AL FINAL DE LA LISTA
	if right:
		result.extend(right[right_idx:]) # SE AGREGA A LA LISTA "result" AL FINAL DE LA LISTA
	return result # RETORNA LA LISTA "result"

def merge_sort(m):
	if len(m)<=1: # SI EL TAMAÑO DE LA LISTA ES MENOR O IGUAL QUE UNO
		return m # RETORNA m
	middle = len(m) // 2  # EN UNA NUEVA VARIABLE LLAMADA "middle", SE ALMACENA LA MITAD DEL TAMAÑO DE LA LISTA
	left = m[:middle] # LA MITAD DEL LADO IZQUIERDO DE LA LISTA SE ALMACENARA EN LA VARIABLE "letf"
	right = m[middle:] # LA MITAD DEL LADO DERECHO DE LA LISTA SE ALMACENARA EN LA VARIABLE "right"
	left = merge_sort(left)
	right = merge_sort(right)
	return list(merge(left, right)) # REGRESA LA LISTA CON EL RESULTADO DE LA FUNCION merge

lista1 = [4, 12, 87, 1, 32, 54, 36, 78, 90, 7] # SE INICIALIZA LA LISTA QUE SE QUIERE ORDENAR
print(merge_sort(lista1))