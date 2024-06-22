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

#### Pattern 1:

|   |   |   |
|---|---|---|
| 0 | 1 | 0 |
| 1 | 1 | 1 |
| 1 | 0 | 1 |

Bias = -1

#### Pattern 2:

|   |   |   |
|---|---|---|
| 1 | 1 | 1 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

Bias = -2

#### Pattern 3:

|   |   |   |
|---|---|---|
| 1 | 1 | 1 |
| 0 | 1 | 0 |
| 0 | 1 | 0 |

Bias = -2

This block differs from other components as it comprises both a controller and datapath:
#### Datapath:
Designing the datapath and controller was a challenging task, as only one adder and multiplier were available for generating addresses and calculating values. To overcome this, four counters (cnt_j, cnt_i, cnt_y, and cnt_x) were utilized to generate addresses representing column and row index and column and row offset of the kernel. Cnt_j and cnt_i were limited by comparators that compared their values with 2, which is the kernel size minus 1. Moreover, the values of x and y were limited by Image_size minus Kernel_size, which is 1. Cnt_9 and cnt_4 were used to select kernel values and load output values, respectively. Additionally, two registers named addr and data were used as address and data accumulators.
![Figure 5: Datapath](https://github.com/Soheilnader/Simple-CNN-with-systemc-RTL/blob/main/doc/image/CONV_DP(1).jpg?raw=true " Figure 5: Datapath")
Figure 5: Datapath

The formula of generating address in order to read data from RAM is as follows: (j,i: index	y, x: offset)

$$
\text{addr} = (j + 4 \times j) + y + 4 \times x
$$

#### Controller:
The controller has three main phases: the address generation phase, calculation phase, and write phase, indicated by red, blue, and yellow colors, respectively.

![Figure 6: Controller](https://github.com/Soheilnader/Simple-CNN-with-systemc-RTL/blob/main/doc/image/CONTROLLER.jpg?raw=true " Figure 6: Controller")
Figure 6: Controller

### ReLU:
ReLU block is a combinational block that receives 4 outputs of a convolutional block and puts 4 values on its output.
### Max pooling block
A max pooling block is a combinational module that reads the 4 values on its input and puts the largest one on its output.
### Result block
A combinational logic is needed to check the results generated by max pooling blocks and in the output, instead of the largest value, ‘1’ must be asserted and for others ‘0’ must be asserted. This output represents the pattern found by the circuit.


##Results

### Matrix1:

|   |   |   |   |
|---|---|---|---|
| 0 | 0 | 0 | 0 |
| 1 | 1 | 1 | 1 |
| 1 | 0 | 0 | 1 |
| 1 | 1 | 1 | 1 |

![Figure 7: Result 1](https://github.com/Soheilnader/Simple-CNN-with-systemc-RTL/blob/main/doc/image/result1.jpg?raw=true " Figure 7: Result 1")
