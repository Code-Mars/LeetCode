class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        vector<double> passRatios;

        // Calculate initial pass ratios
        for (int classIndex = 0; classIndex < classes.size(); classIndex++) {
            double initialRatio =
                classes[classIndex][0] / (double)classes[classIndex][1];
            passRatios.push_back(initialRatio);
        }

        while (extraStudents--) {
            vector<double> updatedRatios;

            // Calculate updated pass ratios if an extra student is added
            for (int classIndex = 0; classIndex < classes.size();
                 classIndex++) {
                double newRatio = (classes[classIndex][0] + 1) /
                                  (double)(classes[classIndex][1] + 1);
                updatedRatios.push_back(newRatio);
            }

            int bestClassIndex = 0;
            double maximumGain = 0;

            // Find the class that gains the most from an extra student
            for (int classIndex = 0; classIndex < updatedRatios.size();
                 classIndex++) {
                double gain =
                    updatedRatios[classIndex] - passRatios[classIndex];
                if (gain > maximumGain) {
                    bestClassIndex = classIndex;
                    maximumGain = gain;
                }
            }

            // Update the selected class
            passRatios[bestClassIndex] = updatedRatios[bestClassIndex];
            classes[bestClassIndex][0]++;
            classes[bestClassIndex][1]++;
        }

        // Calculate the total average pass ratio
        double totalPassRatio = 0;
        for (double passRatio : passRatios) {
            totalPassRatio += passRatio;
        }

        return totalPassRatio / classes.size();
    }
};