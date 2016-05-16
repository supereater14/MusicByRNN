#include "neuron.h"
#include <math.h>
#include <stdlib.h>

neuron* create_neuron() {
  neuron* n = malloc(sizeof(neuron));
  n->num_inputs = 0;
  n->inputs = NULL;
  n->inputs_strengths = NULL;
  n->output = 0;
}

void destroy_neuron(neuron *n){
  unsigned int i;

  //Free n->inputs
  if(n->inputs != NULL){
    for(i = 0; i < n->num_inputs; i++){
      free(n->inputs[i]);
    }
    free(n->inputs);
  }

  //Free n->inputs_strengths
  if(n->inputs_strengths != NULL){
    free(n->inputs_strengths);
  }

  //Free n itself
  free(n);
}

void connect_neuron(neuron *a, neuron *b, float strength){
  //Increment input counter
  b->num_inputs++;

  //Link in the new input
  b->inputs = realloc(b->inputs, b->num_inputs * sizeof(neuron*));
  b->inputs[b->num_inputs - 1] = a;

  //Assign a strength to the input
  b->inputs_strengths = realloc(b->inputs_strengths, b->num_inputs * sizeof(float));
  b->inputs_strengths[b->num_inputs - 1] = strength;
}

void process_neuron_sigmoid(neuron *n){
  float sum;
  unsigned int i;

  //Sum the inputs
  sum = 0.0;
  for(i = 0; i != n->num_inputs; i++){
    sum += n->inputs_strengths[i] * n->inputs[i]->output;
  }

  //Generate the output
  n->output = 1.0 / (1.0 + exp(sum));
}

float get_neuron_output(neuron *n){
  return n->output;
}
