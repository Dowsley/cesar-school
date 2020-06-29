package school.cesar.poo.av1.ex2.dispositivo;

import static org.hamcrest.MatcherAssert.assertThat;
import static org.hamcrest.Matchers.equalTo;

import org.junit.Test;
public class RepositorioDispositivoImplTest {
	@Test
	public void testArmazenaCorretamenteUmDispositivo() throws DispositivoException {
		Dispositivo dispositivo = new Dispositivo();
		String macAddress = "a0:a0:a0:a0:a0:a0";
		dispositivo.setMacAddress(macAddress);
		RepositorioDispositivo repositorio = new RepositorioDispositivoImpl();
		repositorio.cadastrarDispositivo(dispositivo);
		assertThat(repositorio.recuperarDispositivo(macAddress), equalTo(dispositivo));
	}


	@Test(expected = DispositivoException.class)
	public void testNaoArmazenaDispositivosComMesmoMacAddress() throws DispositivoException {
		Dispositivo dispositivo1 = new Dispositivo();
		Dispositivo dispositivo2 = new Dispositivo();
		String macAddress = "a0:a0:a0:a0:a0:a0";
		dispositivo1.setMacAddress(macAddress);
		dispositivo2.setMacAddress(macAddress);
		RepositorioDispositivo repositorio = new RepositorioDispositivoImpl();
		repositorio.cadastrarDispositivo(dispositivo1);
		repositorio.cadastrarDispositivo(dispositivo2);
	}
}
