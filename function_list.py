import os
import re

file_list = []
path = r'project_c\BaseProject\Include'

def print_gestures(gestures):
	print r"\begin{itemize}"
	for gesture in gestures:
		print r'\item \textit{' + gesture[1] + '}\quad ' + gesture[2]
	print r'\end{itemize}'
	

def print_data_types(data_types):
	print r"\begin{itemize}"
	for datatype in data_types:
		print r'\item \textit{' + datatype + '}'
	print r'\end{itemize}'
	
def print_constant(name, value):
	print r'\item \textit{' + name + '\quad ' + value +'}\qquad opis'
	
def print_constants(constants):
	print r"\begin{itemize}"
	for const in constants:
		print_constant(const[0], const[1])
	print r'\end{itemize}'

def normalize_declaration(decl):
#	print repr(decl)
	splitted_decl = re.search(r'(\w+)([*\s]+)(\w+)', decl).groups()
	return splitted_decl[0] + ('*' * splitted_decl[1].count('*')) + ' ' + splitted_decl[2]

def fileHeader(file):
	print r"\subsection{" + file + "}"

def file_list_end():
	print r'\end{itemize}'
	
def file_list_header():
	print r"\section{File location}"
	print r"\begin{itemize}"
	
def section_in_file(content):
	print r"\subsubsection{" + content + '}'
	
def file_in_list_entry(entry):
	print r'\item \textit{' + entry[0] + '}\quad ' + entry[1].replace('\\', '\\textbackslash ')
	
def print_structure(name, fields):
	print r'\textsf{' + name + '}' 
	print '\t' + r'\begin{itemize}'
	for field in fields:
		print '\t\t' + r'\item \textit{' + field + '}\quad',  'opis'
	print '\t' + r'\end{itemize}'
	#'\tstruct',  name, '{\n' +  '\t\t' + ';\n\t\t'.join(fields) + '\t\n\t};'
	print "\ \\\\"
	
def print_function(type, name, rewrited_args):
	print r'\mbox{\textsf{' + type.strip(), name + '(' +  ", ".join(rewrited_args) + ')' + '}}'
	if rewrited_args:
		print '\t' + r'\begin{itemize}'
	for arg in rewrited_args:
		print '\t\t' + r'\item \textit{' + arg + '}\quad',  'opis'
	if rewrited_args:
		print '\t' + r'\end{itemize}'
	print "\n \ \\\\"

def printContent():
	print "\\section{Exposed Functionality}"
	for entry in os.walk(path):
		(dirpath, dirnames, filenames) = entry
		if filenames:		
			for file in filenames:
				if not file.startswith("gp_error") and file.endswith('.h'):
					fileHeader(file)
					file_path = os.path.join(dirpath, file)
					file_list.append((file, dirpath))
					with open(file_path) as f:
						file_content = f.read()
						
						if file.startswith("gp_types"):
							typedefs = r'(?m)^(typedef [^;]+)' 
							section_in_file("Data types")
							print_data_types(re.findall(typedefs, file_content))
						
						constant = r'(?i)#define\s+(\w+)[ ]+(\S+)'
						constants = re.findall(constant, file_content)
						if constants:
							section_in_file("Constants")
							print_constants(constants)
							
						if file.startswith("gp_Main"):
							section_in_file("Gesture declarations")
							gesture = r'((gpOutput\S+)\s+([^\s;]+))'
							gestures = re.findall(gesture, file_content)
							print_gestures(gestures)
							
						name = r"\s*(\w+)\s*;"
						structures = re.findall(r"(?mi)^\s*typedef\s*(?:\w+\s*)?struct\s*{([^}]*)}" + name, file_content)
						if structures:
							section_in_file("Data structures")
						for struct in structures:	
							fields = []
							for field in struct[0].split(';'):
								stripped_field = field.strip()
								if stripped_field:
									fields.append(normalize_declaration(stripped_field))
							print_structure(struct[1], fields)
							
						dataTypes = r'\w+\s*\**'
						functionName = r'[\w]+'
						argument = dataTypes + r'\s*\w+'
						arguments = argument + r'(?:,\s*' + argument + r')*'
						pattern = r'(?mi)^\s*(?P<type>' + dataTypes + ')' + r'\s*(?P<name>' + functionName + r')\s*\((' + arguments + r')\);'
						functions = re.findall(pattern, file_content)
						if functions:
							section_in_file("Functions")
						for function in functions:
							(type, name, args) = function
							args = re.findall(r'(\w+[*\s]+\w+)', args)
							rewrited_args = []
							for arg in args:
								rewrited_args.append(normalize_declaration(arg))
							print_function(type, name, rewrited_args)
						print



if __name__ == "__main__":
	printContent()
	file_list_header()
	for entry in file_list:
		file_in_list_entry(entry)
	file_list_end()