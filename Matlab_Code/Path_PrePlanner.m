%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Code written by Wyatt Kromer
% 
% The purpose of this script is to calculate the setpoints of curves ahead
% of time so that the Arduino PLC doesn't have to do any complex
% calculations at runtime.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all
clc

%% S-Curve
% Note that this scheme will utilize a deadband in order to eliminate the
% possibility of short profiles where the stage does not reach max_v
% This could be changed if necessary for speed

%%%%%%%%%%%%%%%%%%
% Input Parameters
%%%%%%%%%%%%%%%%%%

max_v = 1;              % m/s
max_a = .05;              % m/s^2
time_to_max_a = 15;      % s
PLC_dt = 5;          % s
goal = 0;               % m
deadband_distance = 500; % m, and this is for a single direction. Deadband is actually twice as wide

[x_rec_L,v_rec_L,a_rec_L,t_rec_L,x_rec_S,v_rec_S,a_rec_S,t_rec_S,timestamps] = SPlanner(PLC_dt,max_v,max_a,time_to_max_a,deadband_distance,goal);


% Plot
figure
subplot(311)
plot(t_rec_L,x_rec_L,'LineWidth',2)
ylabel("Distance [m]")
xlabel("Time [s]")
xline(timestamps)
subplot(312)
plot(t_rec_L,v_rec_L,'LineWidth',2)
xlabel("Time [s]")
ylabel("Velocity [m/s]")
xline(timestamps)
subplot(313)
plot(t_rec_L,a_rec_L,'LineWidth',2)
ylabel("Acceleration [m/s^2]")
xlabel("Time [s]")
xline(timestamps)



subplot(311)
hold on
plot(t_rec_S,x_rec_S,'ro','LineWidth',2)
subplot(312)
hold on
plot(t_rec_S,v_rec_S,'ro','LineWidth',2)
subplot(313)
hold on
plot(t_rec_S,a_rec_S,'ro','LineWidth',2)

