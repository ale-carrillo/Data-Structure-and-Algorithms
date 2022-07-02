import java.util.concurrent.Semaphore;

 
public class SemaphoreTest {

	// max 4 people
	static Semaphore semaphore = new Semaphore(4);

	static class PruebaHilos extends Thread {

		String name = "";

		PruebaHilos(String name) {
			this.name = name;
		}

		public void run() {

			try {

				
				System.out.println(name + " : acquiring lock..."); // Adquiriendo cerradura
				System.out.println(name + " : available Semaphore permits now: "  // Permisos de semáforo dispoibles ahora
								+ semaphore.availablePermits());
				
				semaphore.acquire();
				System.out.println(name + " : got the permit!"); // Conseguí el permiso!!

				try {

					for (int i = 1; i <= 5; i++) {

						System.out.println(name + " : is performing operation " + i // está realizando la operación
								+ ", available Semaphore permits : " // permisos de semáforo disponibles:
								+ semaphore.availablePermits());

						// sleep 1 second
						Thread.sleep(1000);

					}

				} finally {

					// calling release() after a successful acquire()
					System.out.println(name + " : releasing lock..."); // soltando el bloqueo ...
					semaphore.release();
					System.out.println(name + " : available Semaphore permits now: " // permisos de semáforo disponibles ahora
								+ semaphore.availablePermits());

				}

			} catch (InterruptedException e) {

				e.printStackTrace();

			}

		}

	}

	public static void main(String[] args) {

		System.out.println("Total available Semaphore permits : " 
				+ semaphore.availablePermits());
	
		PruebaHilos t1 = new PruebaHilos("A");
		t1.start();

		PruebaHilos t2 = new PruebaHilos("B");
		t2.start();

		PruebaHilos t3 = new PruebaHilos("C");
		t3.start();

		PruebaHilos t4 = new PruebaHilos("D");
		t4.start();

		PruebaHilos t5 = new PruebaHilos("E");
		t5.start();

		PruebaHilos t6 = new PruebaHilos("F");
		t6.start();

	}
}
    

