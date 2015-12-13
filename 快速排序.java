import java.util.Scanner;

public class Test {

	private static int[] nums = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int i = 0;
		int n = 10;
		int temp;
		// while ((temp = scanner.nextInt()) != -1) {
		// nums[i] = temp;
		// i++;
		// }

		sort(nums, 1, n - 1);

	}

	public static void sort(int[] a, int start, int end) {

		// System.out.println("刚进入函数，start="+start+",end="+end);

		if (start > end) {
			return ;
		}
		int i, j;
		int m = start - 1;// 排序的基准数
		int n = end;
		while (start != end) {

			for (j = end; j != start; j--) {

				if (a[j] < a[m]) {
					break;
				}
				end = j - 1;
			}
			for (i = start; i != end; i++) {
				if (a[i] > a[m]) {
					break;
				}
				start = i + 1;
			}
			System.out.println("start=" + start + ",end=" + end + ",j=" + j
					+ ",i=" + i);
			if (start != end) {
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}

		}
		// 如果只有俩个数的话，判断俩个数的大小,如果大于，则交换俩个数的大小
		if (a[m] > a[start]) {
			int temp = a[start];
			a[start] = a[m];
			a[m] = temp;
		}

		for (int num : nums) {
			System.out.print(num + " ");
		}
		System.out.println("\n返回的结果result=" + start + "\n");

		sort(nums, 1, start - 1);
		sort(nums, start + 2, n);
	}
}
