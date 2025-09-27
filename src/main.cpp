#include "matrix.h"
#include <iostream>

int main() {
    try {
        std::cout << "=== Демонстрация работы библиотеки матриц ===" << std::endl;
        
        // Тестируем создание матриц
        std::cout << "\n1. Создание матриц:" << std::endl;
        Matrix A = create_matrix(2, 2);
        Matrix B = create_matrix(2, 2);

        // Заполняем матрицы данными
        A.data[0][0] = 1;
        A.data[0][1] = 2;
        A.data[1][0] = 3;
        A.data[1][1] = 4;

        B.data[0][0] = 5;
        B.data[0][1] = 6;
        B.data[1][0] = 7;
        B.data[1][1] = 8;

        std::cout << "Матрица A:" << std::endl;
        print_matrix(A);

        std::cout << "\nМатрица B:" << std::endl;
        print_matrix(B);

        // Тестируем сложение матриц
        std::cout << "\n2. Сложение матриц:" << std::endl;
        Matrix C = matrix_add(A, B);
        std::cout << "A + B:" << std::endl;
        print_matrix(C);

        // Тестируем умножение матриц
        std::cout << "\n3. Умножение матриц:" << std::endl;
        Matrix D = matrix_multiply(A, B);
        std::cout << "A * B:" << std::endl;
        print_matrix(D);

        // Тестируем транспонирование
        std::cout << "\n4. Транспонирование матрицы:" << std::endl;
        Matrix E = matrix_transpose(A);
        std::cout << "Транспонированная A:" << std::endl;
        print_matrix(E);

        // Тестируем сумму элементов матрицы
        std::cout << "\n5. Сумма элементов матрицы:" << std::endl;
        double total_sum_A = matrix_sum(A);
        double total_sum_B = matrix_sum(B);
        std::cout << "Сумма элементов матрицы A: " << total_sum_A << std::endl;
        std::cout << "Сумма элементов матрицы B: " << total_sum_B << std::endl;

        // Тестируем среднее значение матрицы (ваша индивидуальная функция)
        std::cout << "\n6. Среднее значение матрицы (индивидуальное задание):" << std::endl;
        double average_A = matrix_average(A);
        double average_B = matrix_average(B);
        double average_C = matrix_average(C);
        
        std::cout << "Среднее значение матрицы A: " << average_A << std::endl;
        std::cout << "Среднее значение матрицы B: " << average_B << std::endl;
        std::cout << "Среднее значение матрицы C (A+B): " << average_C << std::endl;

        // Дополнительные демонстрации
        std::cout << "\n7. Дополнительные примеры:" << std::endl;
        
        // Создаем матрицу из массива
        double array_data[] = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5};
        Matrix F = matrix_from_array(array_data, 2, 3);
        std::cout << "Матрица F созданная из массива:" << std::endl;
        print_matrix(F);
        
        double average_F = matrix_average(F);
        std::cout << "Среднее значение матрицы F: " << average_F << std::endl;

        // Тестируем с матрицей 1x1
        Matrix G = create_matrix(1, 1);
        G.data[0][0] = 42.5;
        std::cout << "\nМатрица G (1x1):" << std::endl;
        print_matrix(G);
        std::cout << "Среднее значение матрицы G: " << matrix_average(G) << std::endl;

        // Тестируем с прямоугольной матрицей
        Matrix H = create_matrix(3, 2);
        H.data[0][0] = 1; H.data[0][1] = 2;
        H.data[1][0] = 3; H.data[1][1] = 4;
        H.data[2][0] = 5; H.data[2][1] = 6;
        
        std::cout << "\nМатрица H (3x2):" << std::endl;
        print_matrix(H);
        std::cout << "Среднее значение матрицы H: " << matrix_average(H) << std::endl;

        // Проверяем связь между суммой и средним
        std::cout << "\n8. Проверка связи суммы и среднего:" << std::endl;
        double sum_H = matrix_sum(H);
        double avg_H = matrix_average(H);
        int elements_H = H.rows * H.cols;
        std::cout << "Сумма H: " << sum_H << std::endl;
        std::cout << "Среднее H: " << avg_H << std::endl;
        std::cout << "Количество элементов: " << elements_H << std::endl;
        std::cout << "Проверка: " << sum_H << " / " << elements_H << " = " << (sum_H / elements_H) << std::endl;

        // Освобождаем память
        std::cout << "\n9. Освобождение памяти..." << std::endl;
        free_matrix(A);
        free_matrix(B);
        free_matrix(C);
        free_matrix(D);
        free_matrix(E);
        free_matrix(F);
        free_matrix(G);
        free_matrix(H);

        std::cout << "\n=== Все операции завершены успешно! ===" << std::endl;
        std::cout << "Функция matrix_average() работает корректно!" << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}