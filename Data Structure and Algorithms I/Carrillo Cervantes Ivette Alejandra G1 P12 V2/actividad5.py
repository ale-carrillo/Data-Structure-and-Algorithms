# Carrillo Cervantes Ivette Alejandra
# Juárez Juárez María José
# Estructura de Datos y Algoritmos I

def mystery(S):
	N = S.split()
	N = ''.join(N)
	if len(N) == 1 or len(N) == 0:
		return True
	else:
		if N[0] == N[-1] and mystery (N[1:-1]):
			return True
		else:
			return False

test = input('\nIngresa una cadena:\n')
print(mystery(test))