# Very simple Convolutional neural network (CNN) for image recognition with SystemC
For this assignment, our goal is to create a module that can search for specific patterns in input images. This module is called the Pattern Finder Circuit and it is made up of three convolutional blocks, each with 3x3 kernels. The purpose of each convolutional block is to search for a particular pattern in a 4x4 input image. After each convolutional block, there is a ReLU activation function followed by a 2x2 Max Pool layer.

![Figure 1: Schematic of the circuit](https://github.com/Soheilnader/Simple-CNN-with-systemc-RTL/blob/main/doc/image/pattern_finder.png?raw=true "Figure 1: Schematic of the circuit")
Figure 1: Schematic of the circuit

## Introduction
The first step in image processing involves passing the input image through a convolutional layer. This layer applies filters to the image to extract features like shapes. Sometimes, the output of this stage passes through an activation function like the ReLU. Figure 2 shows the result of applying ReLU to a sample matrix. In Figure 3, we can see the convolutional process in action with a kernel size of 3 and a stride of 1.

![Figure 2: ReLU](https://github.com/Soheilnader/Simple-CNN-with-systemc-RTL/blob/main/doc/image/Relu_apply.png?raw=true "Figure 2: ReLU")
Figure 2: ReLU

![Figure 3: Convolution](https://github.com/Soheilnader/Simple-CNN-with-systemc-RTL/blob/main/doc/image/Conv.png?raw=true "Figure 3: Convolution")
Figure 3: Convolution

After the convolutional layers, the feature maps are passed through a pooling layer to down-sample them. This helps to make the neural network more efficient and less likely to overfit by reducing the spatial dimensions of the feature maps. Figure 4 demonstrates the effect of applying the Max Pooling function with a 2x2 stride on a matrix.

![Figure 4: Max Pooling](https://github.com/Soheilnader/Simple-CNN-with-systemc-RTL/blob/main/doc/image/maxpool.png?raw=true "Figure 4: Max Pooling")
Figure 4: Max Pooling

Convolutional blocks play an important role in the early stages of a Convolutional Neural Network (CNN). Their primary objective is to extract features from the input image. These blocks are usually repeated several times throughout the network, with each block extracting more complex features from the output of the previous block. This hierarchical structure allows the network to learn increasingly complex features, leading to better image recognition performance.

## Implementation
In Figure 1, the complete schematic of this circuit is illustrated. Each component is described below:
### RAM block
To save the input image at the beginning of the task, a RAM block with 16 rows (8-bit) is required. Once a complete positive pulse is received on the start input signal, the convolutional blocks begin their computations concurrently. Once all computations are completed, the done output signal will be asserted.

### Convolutional Blocks
To implement the required functionality, three convolutional blocks are necessary. These blocks need to be instantiated using a generate statement, and the number of blocks used must be configurable using generic parameters. The convolutional block is a sequential module that employs one adder and one multiplier. The kernel's values are obtained using 9 generic parameters. This module begins its computations after a complete pulse is received on the start_conv input signal. Additionally, the done_conv output signal must be asserted when the results are ready. The kernels used in this project are as follows:
Pattern 1:

| | | |
| :------------: | 
|0   |1   |0   |
|1   | 1  | 1  |
|0   |  1 |  0 |
Bias = -1

Pattern 2:

| | | |
| :------------: | 
|1   |1   |1   |
|1   | 0  | 0  |
|1   |  1 |  1 |
Bias = -2

Pattern:

| |||
| :------------: | 
|1   |1   |1   |
|0   | 1  | 0  |
|0   |  1 | 0 |

Bias = -2

