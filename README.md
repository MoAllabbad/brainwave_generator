## Brainwave Generator

A project I worked on required reading brainwaves from the head through electrodes. We were a team of six including electrical and software engineers. The hardware part of the team was responsible of reading the signal filtering it, amplifying it, sampling it and sending it to the software side for further analysis. As head of the hardware side and as the software team needed to test their side independently, I decided to design a software based brainwave generator, to give it to the software side to implement their initial testing based on the theoretical or ideal signal obtained from the brain. In this post, I will explain how that is implemented. But to understand that better, I will start by explaining the biology of a brainwave, the basic constituents that would make a brainwave and its signal analysis, leading to the design process of the software, and finally the software implementation. 

### Biology and physics of brainwaves:
The brain communicates with the body using the nervous system. The nervous system carries electrical signals. The brain manipulates voltage fluctuations to induce electric current, traveling through the body with the encoded information to the intended destination. Physically, these electric currents are the same as those inside any electrical conductor, and thus the same laws of physics apply. Namely Faraday's law: first that a changing electric current will cause a changing electric field which will in turn induce a changing magnetic field. So, if the brain is sending electric currents, then these currents are generating magnetic fields. Then, if we can observe the magnetic field, or what we also call brainwave, how would we make sense of it? In theory, if different states of the brain would result in unique patterns in the electric signals, then observing these patterns would be a good indication for the corresponding brain state. Obviously, the brain is very complex with so many functionalities, many of which are not well understood, so it is much easier to focus on something specific rather than try to make sense of the whole brain. 
Luckily, for our project purpose, there is already a body of research showing a correlation between the level of sleepiness or alertness of a person and the dominant frequency of the brainwaves. 

### How to interpret brainwaves?
For the outside observer, a brainwave is only a change in magnetic field, which if presented to an electric conductor would induce voltage in the conductor. But what do these mean and how do we start to interpret them? If we had access to individual neurons, then we can observe their behavior and maybe using super computers, or possibly quantum computers, to reach an understanding of their collective behavior. But, from outside the brain, with billions of neurons firing together, variation of the signal in time may not give the best collective information. However, similar neuron signals, or their collective firing would result in similar frequencies. And the research shows, depending on which frequency is dominant, we can know the dominant state of the brain.

Looking at the table below which mimics imperical data, we see the brainwave for each frequency band and its corresponding state. For example, below 4Hz is a deep sleep state. Then the raw signal at the top of the table represents a combination of these bands with one band being dominant depending on the state of the brain.

 ![EEG frequency bands. Source: Conorrus Somanno](https://conorrussomanno.files.wordpress.com/2012/06/2.png)   
 EEG frequency bands. Source: Conorrus Somanno


Another source is also from [neurosky](http://support.neurosky.com/kb/science/eeg-band-frequencies), which supports the same data but also adds the gamma bands that is above 35Hz to 50Hz.

So how do we know which frequency is dominant?
To know which frequency is dominant, it means we must distinguish between the different frequencies. That is a topic for DSP (digital signal processing) and Fourier analysis.

## Fourier analysis:
Fourier analysis is a set of tools introduced by the mathematician and physicist Joseph Fourier. One tool is the Fourier series which essentially says that any signal or mathematical function can be represented by a sum of periodic functions. Another tool is the Fourier transform which can transform the signal from its time representation to its frequency components and vice versa, and a practical version of it that is used in DSP is the FFT (Fast Fourier Transform). So, if we have a signal ready, and we want to examine its frequency components then, we use the FFT. For our project, that is what we do; we obtain the signal from the brain, perform some analog processing then start the digital processing by performing the FFT. But if we do not have the signal ready, or if we want to model a signal from scratch, and we want to make sure that it does have the necessary frequency components so that the FFT yields the correct results, then we need to use Fourier series analysis.


## Generating brainwaves:
For this project, we are interested in a signal ranging from 0Hz to about 50Hz. So, what I can start with is adding periodic signals, such as a sinusoidal, ranging from 0Hz to 50Hz.

***To be continued . . .***