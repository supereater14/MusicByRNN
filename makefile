rnn_test: neuron.o
	gcc src/rnn_test.c bin/neuron.o -o bin/rnn_test -lm

neuron.o:
	gcc src/neuron.c -o bin/neuron.o -lm -c

clean:
	rm bin/*
