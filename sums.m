%% Clean up
close all;
clear all;
clc;


%% Run sums.cpp program for different N
% Relative errors for single / double prec. experiments.
n      = 9; % 10^10 exceeds range of a normal int, such that N overflows.
single = zeros(n,1);
double = zeros(n,1);

for i=1:n
    % Display step in terminal for convenience.
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
loglog(1:n, (single), 'r-');
loglog(1:n, (double), 'b-');
ylabel('log$_{10}($rel. error$)$', 'interpreter', 'latex', 'FontSize', 14);
xlabel('log$_{10}(n)$', 'interpreter', 'latex', 'FontSize', 14);
h = legend('single prec.','double prec.');
set(h, 'interpreter', 'latex', 'FontSize', 14);