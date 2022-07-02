"""
CARRILLO CERVANTES IVETTE ALEJANDRA
ESTRUCTURA DE DATOS Y ALGORITMOS - GRUPO 1
"""

def activities(s, f, n): # FUNCION ACTIVIDADES, TIENE COMO PARAMETROS LA LISTA s, f Y LA VARIABLE n
	print('\nSelected activities are:\n')
	i = 0
	print(f'A{i+1}')
	j = 1
	inicio = 1
	incremento = 1
	for j in range(inicio, n, incremento): # CICLO FOR
		if s[j]>=f[i]: # SI EL SEGUNDO INDICE DE s ES MAYOR O IGUAL AL PRIMER INDICE DE f
			print(f'A{j+1}') # IMPRIME EL HORARIO
			i = j # i SE IGUALA A j

s = [1, 2, 3, 2, 4, 5, 6, 8, 7] # horarios inicio de actividades
f = [4, 5, 6, 8, 6, 7, 7, 12, 9] # horario fin de actividades
n = len(s)
activities(s, f, n)