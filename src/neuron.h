#ifndef NEURON_H
#define NEURON_H

#include <stdlib.h>

typedef struct neuron {
  unsigned int num_inputs;
  struct neuron** inputs;
  float* inputs_strengths;
  float output;
} neuron;

/*Creates a blank neuron*/
neuron* create_neuron();

/*Destroys an existing neuron
 *n - Neuron to destroy
 */
void destroy_neuron(neuron *n);

/*Connects one neuron to another
 *a is added as an input to b
 *a - first neuron
 *b - second neuron
 *strength - The strength of the connection between the neurons
 */
void connect_neuron(neuron *a, neuron *b, float strength);

/*Processes a neuron using a sigmoid function, produces output
 *n - neuron to process
 */
void process_neuron_sigmoid(neuron *n);

/*Fetches the output of a neuron
 *Useful for getting the final output of a network or for debugging
 *n - neuron to fetch output of
 */
float get_neuron_output(neuron *n);

#endif /*NEURON_H*/
