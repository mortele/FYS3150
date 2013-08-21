%% Clean up
close all;
clear all;
clc;


%% Load in data from the output of derivative.cpp
ddx = load('ddx.dat')';
h   = load('h.dat')';

%% Plot results
ddx = abs(ddx - 1/3)/(1/3);
loglog(h, ddx);
hold on;

% Mark the theoretically optimal value.
hOptimal = sqrt(sqrt(2) * 1e-15 * atan(sqrt(2) * 9));
loglog([hOptimal hOptimal], [10^(-15) 10^(15)], 'r-');

ylabel('log$_{10}($rel. error$)$', 'interpreter', 'latex', 'FontSize', 14);
xlabel('log$_{10}(h)$', 'interpreter', 'latex', 'FontSize', 14);
q = legend('rel. error in approximation','theoretically optimal h');
set(q, 'interpreter', 'latex', 'FontSize', 14, 'location', 'NorthWest');
axis([min(h) max(h) min(ddx) max(ddx)]);