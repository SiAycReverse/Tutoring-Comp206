# text in color: target (name of the commend)
# first target in the makefile is the default target
# using @ to suppress echoing command

# all is the default command

# to exectue a specific target:  make <target>
all: say_hello generate

say_hello:
	@echo "Hello World"

generate:
	@echo "Creating empty text files..."
	touch file-{1..10}.txt

clean:
	@echo "Cleaning up..."
	rm *.txt
