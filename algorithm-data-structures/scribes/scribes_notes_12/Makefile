
default: main.pdf

main.pdf: main.tex
	pdflatex main
	bibtex main
	
clean:
	/bin/rm -f *.dvi
	/bin/rm -f *.pdf
	/bin/rm -f *.aux
	/bin/rm -f *.log
	/bin/rm -f *.bbl
	/bin/rm -f *.blg
	/bin/rm -f *.fdb_latexmk
	/bin/rm -f *.fls
