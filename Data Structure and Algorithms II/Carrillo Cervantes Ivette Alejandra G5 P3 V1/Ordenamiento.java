// Carrillo Cervantes Ivette Alejandra
// Estructura de Datos y Algoritmos - Grupo 5

import java.util.Arrays;

public class Ordenamiento{
	static void countingSort(char arr[]){
		int n = arr.length;
		int i, j;
		char max = Utilerias.valorMaximo(arr);
		int [] count = new int[10]; // de A-J hay 10 elementos
		Utilerias.llenarCeros(count);
		for(i = 0; i<n; i++){
			if(arr[i]=='A'){
				count[0]++;
			}
			if(arr[i]=='B'){
				count[1]++;
			}
			if(arr[i]=='C'){
				count[2]++;
			}
			if(arr[i]=='D'){
				count[3]++;
			}
			if(arr[i]=='E'){
				count[4]++;
			}
			if(arr[i]=='F'){
				count[5]++;
			}
			if(arr[i]=='G'){
				count[6]++;
			}
			if(arr[i]=='H'){
				count[7]++;
			}
			if(arr[i]=='I'){
				count[8]++;
			}
			if(arr[i]=='J'){
				count[9]++;
			}
		}
		System.out.println("\n -> Cuenta de los elementos: ");
		Utilerias.printArray(count);
		System.out.println("   A  B  C  D  E  F  G  H  I  J");
		
		for(i = 1; i < 10; i++){
			count[i]= count[i]+count[i-1];
		}
		System.out.println("\n -> Suma de los elementos: ");
		Utilerias.printArray(count);
		System.out.println("   A  B  C  D  E  F  G  H  I  J");

		char [] finalArr = new char[n];
		int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, ii = 0, jj = 0;
		for(i = n-1; i>=0; i--){
			if(arr[i]=='A'){
				if(a==0){
					a = count[0];
					a--;					
					finalArr[a] = arr[i];		
				}else{
					a--;
					finalArr[a] = arr[i];
				}
			}
			if(arr[i]=='B'){
				if(b==0){
					b = count[1];
					b--;
					finalArr[b] = arr[i];			
				}else{
					b--;
					finalArr[b] = arr[i];
				}
			}
			if(arr[i]=='C'){
				if(c==0){
					c = count[2];
					c--;
					finalArr[c] = arr[i];		
				}else{
					c--;
					finalArr[c] = arr[i];
				}
			}
			if(arr[i]=='D'){
				if(d==0){
					d = count[3];
					d--;
					finalArr[d] = arr[i];
				}else{
					d--;
					finalArr[d] = arr[i];
				}
			}
			if(arr[i]=='E'){
				if(e==0){
					e = count[4];		
					e--;
					finalArr[e] = arr[i];			
				}else{
					e--;
					finalArr[e] = arr[i];
				}
			}
			if(arr[i]=='F'){
				if(f==0){
					f = count[5];		
					f--;
					finalArr[f] = arr[i];			
				}else{
					f--;
					finalArr[f] = arr[i];
				}
			}		
			if(arr[i]=='G'){
				if(g==0){
					g = count[6];		
					g--;	
					finalArr[g] = arr[i];		
				}else{
					g--;
					finalArr[g] = arr[i];
				}
			}
			if(arr[i]=='H'){
				if(h==0){
					h = count[7];		
					h--;
					finalArr[h] = arr[i];			
				}else{
					h--;
					finalArr[h] = arr[i];
				}
			}
			if(arr[i]=='I'){
				if(ii==0){
					ii = count[8];		
					ii--;
					finalArr[ii] = arr[i];			
				}else{
					ii--;
					finalArr[ii] = arr[i];
				}
			}
			if(arr[i]=='J'){
				if(jj==0){
					jj = count[9];		
					jj--;	
					finalArr[jj] = arr[i];		
				}else{
					jj--;
					finalArr[jj] = arr[i];
				}			
			}
		}
		System.out.println("\n -> El array ordenado, es el siguiente:");
		Utilerias.printArray(finalArr);
	}

}