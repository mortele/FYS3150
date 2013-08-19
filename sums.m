%% Clean up
close all;
clear all;
clc;


%% Run sums.cpp program for different N
% Relative errors for single / double prec. experiments.
n      = 8;
single = zeros(n,1);
double = zeros(n,1);

for i=1:n
    i
    
    % Run the program.
    argument = sprintf('./sums.app %d', i);
    system(argument);
    
    % Fetch resulting data from file sums.dat.
    data      = load('sums.dat');
    double(i) = data(1);
    single(i) = data(2);
end


%% Plot results
figure(1); hold on;
plot(1:n, log10(single), 'r-');
plot(1:n, log10(double), 'b-');