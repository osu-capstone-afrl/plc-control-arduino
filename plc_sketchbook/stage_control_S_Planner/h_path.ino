// ---------------
// Calculate Path
// ---------------

int calculate_path()  {

  // Get ready to retreive stored data
  int lastPoint = last_pointer(histPointer);

  // Data Pre-Processing //
  //Check for Danger
    //To be implemented later
    
  // Are We in a "Short Profile" (s-curve will have no components of max velocity)
  //j = max_a / time_to_max_a //ALL OF THESE NEED GLOBAL DEFINITIONS
  //
  //bool short_profile = max_v * ( time_to_max_a + max_v / max_a) > goal
  //if short_profile {
  //  profile_max_v = max_a * (math.sqrt(goal / max_a - 0.75 * time_to_max_a **2) - 0.5 * time_to_max_a)
  //} else {
  //  profile_max_v = max_v;
  //}
  
  // Determine which of the 7 zones we are in
    // 1 - ramp up acceleration (until @ max acceleration)
    // 2 - accelerate at max acceleration (until @ profile_max_v - time_to_max_a * max_a/2)
    // 3 - ramp down acceleration (until @ max v)
    // 4 - continue at max velocity (until @ goal / profile_max_v) (until @ a possibly precalculated distance for full deceleration)
    // 5 - ramp up deceleration (until @ max acceleration)
    // 6 - accelerate at max deceleration
    // 7 - ramp down deceleration
  
  // Path Planning
  // Calculate point based on which of the 7 zones we are in
    // 1 - ramp up acceleration
    // 2 - accelerate at max acceleration
    // 3 - ramp down acceleration
    // 4 - continue at max velocity
    // 5 - ramp up deceleration
    // 6 - accelerate at max deceleration
    // 7 - ramp down deceleration

  // PID & Feed-Forward Tuning

  // Issue Command
  int requested_control = command_hist[histPointer] + (distance_hist[histPointer]-desired_offset);
  command_hist[histPointer] = requested_control;
  return requested_control; //UPGRADE CODE HERE


}
