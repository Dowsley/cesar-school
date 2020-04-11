package school.cesar.poo.av1.ex2.leitura;

import org.junit.Test;

import school.cesar.poo.av1.ex2.dispositivo.Dispositivo;
import static org.hamcrest.MatcherAssert.assertThat; 
import static org.hamcrest.Matchers.*;
public class RepositorioLeituraImplTest {
	@Test
	public void testArmazenaCorretamenteUmaLeitura() {
		Dispositivo dispositivo = new Dispositivo();
		dispositivo.setMacAddress("a0:a0:a0:a0:a0:a0");
		RepositorioLeitura repositorio = new RepositorioLeituraImpl();
		LeituraPressao leitura = new LeituraPressao();
		leitura.setDispositivo(dispositivo);
		repositorio.cadastrarLeitura(leitura);
		assertThat(repositorio.listarLeituras(dispositivo), hasEntry(leitura));
	}
}
