package br.com.Mateus.Brpp;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Formatter;
import java.util.HashMap;
import java.util.Map;

public class BrppCompiler {

	private static Map<String, String> variaveis = new HashMap<String, String>();
	private static Formatter program;
	
	public static boolean compile(String path) {
		String file = path.substring(0, path.length() - 4);
		file = file.concat("ino");
		try {
			// inputFile = new Scanner(input);
			program = new Formatter(file);
			byte[] encoded = Files.readAllBytes(Paths.get(path));
			String liness = new String(encoded);
			String[] lines = liness.split("\n");
			if (proccess(lines))
				return true;
			else
				return false;
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {

		}
		return false;

	}

	public static boolean proccess(String[] lines) {
		for (String line : lines) {
			String command = line;
			if ((command.contains(";") || command.contains("{") || command
					.contains("}"))) {
				if (command.contains("Fabrica")) {
					command = command.replace("Fabrica", "public class");
				}
				if (command.contains("usar")) {
					command = command.replace("usar ", "#include <");
					command = command.replace(";", ".h>;");
				}
				if (command.contains("Configuracao"))
					command = command.replace("Configuracao", "void setup");
				if (command.contains("Principal"))
					command = command.replace("Principal", "void loop");

				if (command.contains("esperar("))
					command = command.replace("esperar", "delay");
				if (command.contains("SemRetorno"))
					command = command.replace("SemRetorno", "void");
				if (command.contains("Restrito")) {
					command = command.replace("Restrito", "private");
				}
				if (command.contains("se (") || command.contains("se(")) {
					command = command.replace("se ", "if ");
					command = command.replace("faca", "");
					if (command.contains("=")
							&& !((command.contains(";")
									|| command.contains("==")
									|| command.contains("<") || command
										.contains(">"))))
						return false;
				}
				if (command.contains("enquanto (")
						|| command.contains("enquanto(")) {
					command = command.replace("enquanto ", "while ");
					command = command.replace("faca", "");
					if (command.contains("=")
							&& !((command.contains(";")
									|| command.contains("==")
									|| command.contains("<") || command
										.contains(">"))))
						return false;
				}
				if (command.contains("USB.conectar()"))
					command = command.replace("USB.conectar()",
							"Serial.begin(9600)");
				if (command.contains("USB.enviar"))
					command = command.replace("USB.enviar", "Serial.print");

				if (command.contains("Numero") || command.contains("Palavra")
						|| command.contains("Condicao")
						|| command.contains("Verdade")
						|| command.contains("Mentira")) {
					while (command.contains("Numero")
							|| command.contains("Palavra")
							|| command.contains("Condicao")
							|| command.contains("Verdade")
							|| command.contains("Mentira")) {

						command = addVar(command, command.contains("=") ? true
								: false);
					}
				}
				if (command.contains("}") && !command.contains("\n")) {
					command = command.replace("}", "");
					command = command.concat(command.substring(
							command.indexOf(';') + 1,
							command.lastIndexOf('\t') + 1) + "}");
				} else if (command.contains("}"))
					command = "}";
				if (command.contains("Pino.definirModo")) {
					command = command.replace("Pino.definirModo", "pinMode");
					command = command.replace("Saida", "OUTPUT");
					command = command.replace("Entrada", "INPUT");
				}
				if (command.contains("Pino.ler(A")) {
					command = command.replace("Pino.ler", "analogRead");
					command = command.replace("Analogica.", "A");
				}
				if (command.contains("Pino.ler(")) {
					command = command.replace("Pino.ler", "digitalRead");
					command = command.replace("Digital.", "");
				}
				if (command.contains("Pino.escrever(A")) {
					command = command.replace("Pino.escrever", "analogWrite");
					command = command.replace("Analogica.", "A");
					command = command.replace("APD.", "");
				}
				if (command.contains("Pino.escrever(")) {
					command = command.replace("Pino.escrever", "digitalWrite");
					command = command.replace("Digital.", "");
					command = command.replace("Ligado", "HIGH");
					command = command.replace("Desligado", "LOW");
				}
				if (command.contains("Pino.ligar(")) {
					command = command.replace("Digital.", "");
					String pin = command.substring(command.indexOf('(') + 1,
							command.indexOf(')'));
					command = command.replace("Pino.ligar(" + pin + ")",
							"digitalWrite(" + pin.trim() + ",HIGH)");
				}
				if (command.contains("Pino.desligar(")) {
					command = command.replace("Digital.", "");
					String pin = command.substring(command.indexOf('(') + 1,
							command.indexOf(')'));
					command = command.replace("Pino.desligar(" + pin + ")",
							"digitalWrite(" + pin.trim() + ",LOW)");
				}
				if (command.contains("responder"))
					command = command.replace("responder", "return");
				if (command.contains("<native>"))
					command = line.replace("<native>", "");
				if (command.contains("//")) {
					command = line;
				}
				program.format("%s\n", command);
				System.out.println(command);
				command = "";
			} else if (line.length() > 1 && !line.contains("//")) {
				System.out.println("fu");

				return false;
			} else {
				program.format("%s\n", command);
				System.out.println(command);

			}
		}
		program.close();
		return true;

	}

	public static String addVar(String line, boolean contains) {

		String name = "";
		String value = "-";
		String var = "";
		if (line.contains("Numero")) {

			if (!line.contains("Decimal")) {
				var = line.replace("Numero", "int");

			} else {

				boolean co;
				if (line.contains(".") || line.contains("+")
						|| line.contains("-") || line.contains("/")
						|| line.contains("%")) {
					co = true;
				} else {
					co = false;
				}
				var = line.replace("NumeroDecimal", "float");
			}
			// System.out.println(var);

			// name = var.substring(var.indexOf('t') + 2,
			// contains ? var.indexOf('=') - 1 : var.indexOf(';'));
			// value = contains ? var.substring(var.indexOf('=') + 2,
			// var.indexOf(';')) : "-";
		}

		if (line.contains("Palavra")) {
			var = line.replace("Palavra", "String");
			var = var.replace('\'', '\"');
			// name = var.substring(var.indexOf('g') + 2,
			// contains ? var.indexOf('=') - 1 : var.indexOf(';'));
			// value = contains ? var.substring(var.indexOf('\"') + 1,
			// var.lastIndexOf('\"')) : "-";
		}
		if (line.contains("Condicao") || line.contains("Verdade")
				|| line.contains("Mentira")) {
			/*
			 * if (line.contains("Verdade")) { // value = "true"; } else if
			 * (line.contains("Mentira")) { // value = "false"; } else if
			 * (!line.contains("=")) { // value = "-"; } else
			 */
			if (line.contains("=")
					&& !(line.contains("<") || line.contains("<=")
							|| line.contains(">") || line.contains(">=")
							|| line.contains("==") || line.contains("!="))) {

				System.out
						.println("h� um erro na declara��o desta vari�vel..."
								+ line.substring(line.indexOf('o', 'a') + 2,
										line.indexOf(';') + 1)
								+ " ela s� pode assumir como valores Verdade ou Mentira.");
			}
			var = line.replace("Condicao", "boolean");
			var = var.replace("Mentira", "false");
			var = var.replace("Verdade", "true");
			// name = var.substring(var.indexOf('n') + 2,
			// contains ? var.indexOf('=') - 1 : var.indexOf(';') - 1);
			// value = contains ? value : "-";

		}

		if (!variaveis.containsKey(name)) {
			// saveVar(name, value);

		} else {
			System.out.println("Vari�vel j� existe com esse nome");
		}
		return var;
	}

	public static void saveVar(String name, String value) {
		variaveis.put(name, value);
	}
}
