#ifndef NETWORK_H
#define NETWORK_H

#include <stdlib.h>
#include "neuron.h"

typedef struct network {
  layer* layers;
} network;

/*initializes all errors to 0, and final layers' errors as appropriate
 *nw - network to initialize
 *true_output - true outputs to which to compare network output
 */
void init_errors(network* nw, layer true_output);

/*flows information forward to compute
 *nw - network to forward propagate
 */
void forward_propagate(network* nw);

/*flows errors backward to train
 *nw - network to backpropagate
 *network_input - input layer values
 */
void back_propagate(network* nw, layer network_input);

#endif /*NETWORK_H*/
