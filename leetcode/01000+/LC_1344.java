// Solve 2026-06-19

class LC_1344 {

    public double angleClock(int hour, int minutes) {
        // double hourAngle = (double) (hour % 12 * 60 + minutes) / 720 * 360;
        double hourAngle = (double) (hour % 12 * 60 + minutes) / 2;
        // double minuteAngle = (double) minutes / 60 * 360;
        double minuteAngle = (double) minutes * 6;

        double diffAngle = Math.abs(hourAngle - minuteAngle);
        diffAngle = Math.min(diffAngle, 360 - diffAngle);
        return diffAngle;
    }

}
